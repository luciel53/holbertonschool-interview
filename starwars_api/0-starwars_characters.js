#!/usr/bin/node

const request = require('request');
const arg = process.argv[2];
const url = (`https://swapi-api.hbtn.io/api/films/${arg}`);

const charNames = (names, i = 0) => {
  if (i === names.length) return;
  request(names[i], (error, response, body) => {
    /* convert a string of characters JSON to a javascript object and print it */
    console.log(JSON.parse(body).name);
    /* call recursively the function charnames and increment it to pass at the next character */
    charNames(names, i + 1);
  });
};

/* request to the API to recover movie informations */
request(url, function (error, response, body) {
  /* extract url of characters from the body json response and store it in a var char */
  const char = JSON.parse(body).characters
  /* call the function charNames to print the characters */
  charNames(char);
});

