// express module 설치
// npm install express

// express : javascript 함수이름
var express = require('express');

// web server인 app javascript object 생성
var app = express();

// argument에 있는 함수 => callback함수 
// callback함수 : node.js가 web server에서 실행 결과(response객체)를 받으면
//               실행하는 함수
// request : web browser가 보낸 request message javascript object
// response : web server가 web browser에게 보내는 response javascript object
// app.use => middleware라고 부름
app.use(function(request, response) {
    // send method : web server에서 web browser로 보내는 data를 전송하는 method
//    response.send('<h1>안녕하세요!</h1>');
    response.send('<h1>안녕하세요!</h1><h2>반갑습니다.</h2>');
});

// web server 실행
app.listen(52273, function() {
    console.log('Server Running at http://127.0.0.1:52273');
});