var express = require('express');

// web server 실행
var app = express();

// public directory를 정적(static) default folder로 지정
app.use(express.static('public'));

// router 실행
// app.all : get, post, put, delete method 4개 모두 지원
// '/a' => URI의 path를 의미 (개발자가 임의로 이름을 지정 가능)
app.all('/a', function(request, response) {
    response.send('<h1>Page A</h1>');
});

app.all('/b', function(request, response) {
    response.send('<h1>Page B</h1>');
});

app.all('/c', function(request, response) {
    response.send('<h1>Page C</h1>');
});

// web server 실행
app.listen(52273, function() {
    console.log('Server Running at http://127.0.0.1:52273');
});