var express = require('express');

// web server 실행
var app = express();

// public directory를 정적(static) default folder로 지정
// express.static() middleware 사용
// 'public' => folder 이름
// express.static('public') 실행 방법 : Node.js가 public folder의 index.html를 실행
app.use(express.static('public'));

// public folder의 index.html이 실행되면 우선순위가 낮은 app.use() 내용 실행 안됨
app.use(function(request, response) {
    response.send('<h1>Hello Middleware..!</h1>');
});

// web server 실행
app.listen(52273, function() {
    console.log('Server Running at http://127.0.0.1:52273');
});