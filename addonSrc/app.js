var express = require('express');
const addOnTest = require('./build/Release/addon');
var app = express();

app.get("/",function(req,res){

	var str = addOnTest.hello() + "\n";

	res.send(str);
});

var portno = 9000;

app.listen(portno,function(){
	console.log('listening on port' + portno);
});