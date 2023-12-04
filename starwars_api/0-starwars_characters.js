const request = require('request');

const url = ('https://swapi-api.hbtn.io/api/films/' + process.argv[2]);
request(url, function (error, response, body) {
  if (body === undefined) {
    reject(error);
  } else {
    body = JSON.parse(body);
	body.characters.forEach(char => {
		if (!error) {
			const character = JSON.parse(body);
			console.log(character.name);
		} else {
			console.error('Error:', error);
		}
	})
  }
});

