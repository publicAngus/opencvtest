const addon = require('./build/Release/addon');

console.log(addon.hello());

var obj = addon.getObj("im param");
console.log(obj);

addon.callmeBack(cb);
function cb(arg0,arg1){
	console.log(arguments);
	console.log(arg0);
	console.log(arg1);
}

var func = addon.getJsFunc();
func("helloworld");
