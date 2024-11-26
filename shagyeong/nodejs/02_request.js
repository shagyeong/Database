// request module 설치
// npm install request
// request => javascript object
var request = require('request');

// request의 2번째 argument에 있는 함수 => callback 함수
request('http://www.google.com', function(error, response, body) {
    // body javascript object에는 www.google.com server에서 web browser에 보낸
    // html, css, javascript등의 data를 갖고 있음
    console.log(body);
});