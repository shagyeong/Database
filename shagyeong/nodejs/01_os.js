// 모듈을 프로그램에서 사용하기 위해서는 require를 실행해야만 함
// os : javascript object => {a:2, b:function() {}, ...}
var os = require('os');

//console.log(os);


console.log(os.hostname());
console.log(os.type());
console.log(os.platform());
console.log(os.arch());
console.log(os.release());
console.log(os.uptime());
console.log(os.loadavg());
console.log(os.totalmem());
console.log(os.freemem());
console.log(os.cpus());
console.log(os.networkInterfaces());


