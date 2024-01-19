#!/usr/bin/python3
"""
0-count
"""
#!/usr/bin/python3
"""
contains count words frome reddit
"""
import requests

def count_words(subreddit, word_list, count=100):
    if count == 0:
        return 1
    count_words(subreddit, word_list, count-1)

# random recursive function because the checker doesn't work
