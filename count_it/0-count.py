#!/usr/bin/python3
"""
0-count
"""

import requests

def count_words(subreddit, word_list, after=None, count_dict=None):
    if count_dict is None:
        count_dict = {}

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    params = {'limit': 25}
    if after:
        params['after'] = after

    headers = {'User-Agent': 'YourAppName/1.0 (by /u/YourRedditUsername)'}

    response = requests.get(url, params=params, headers=headers)

    if response.status_code != 200:
        print(f"Error accessing subreddit '{subreddit}': {response.status_code}")
        return

    data = response.json()
    posts = data.get('data', {}).get('children', [])

    for post in posts:
        title_words = post['data']['title'].lower().split()
        for word in word_list:
            if word.lower() in title_words:
                count_dict[word.lower()] = count_dict.get(word.lower(), 0) + title_words.count(word.lower())

    after = data.get('data', {}).get('after')
    if after:
        count_words(subreddit, word_list, after, count_dict)
    else:
        if not posts:
            print(f"No matching posts in subreddit '{subreddit}'")
        else:
            sorted_counts = sorted(count_dict.items(), key=lambda x: (-x[1], x[0]))
            for keyword, count in sorted_counts:
                print(f"{keyword}: {count}")
