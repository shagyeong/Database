var express = require('express');

// web server 실행
var app = express();

// app.use parameter에 들어가는 callback함수를 middleware라 부름
app.use(function(request, response, next) {
    console.log('first');
    // next() => 다음 middleware인 app.use를 실행하라는 의미
    next();
});

// request, response : javascript object
app.use(function(request, response, next) {
    console.log('second');
    // requst object에 새로운 속성인 test를 추가
    request.test = 'request.test';
    response.test = 'response.test';
    next();
});

app.use(function(request, response, next) {
//    response.send('<h1>Hello Middleware..!</h1>');
    response.send('<h1>' + request.test + '::' + response.test + '</h1>');
});

// web server 실행
app.listen(52273, function() {
    console.log('Server Running at http://127.0.0.1:52273');
});