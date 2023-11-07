start = document.getElementById('start');
stop  = document.getElementById('stop');
fast  = document.getElementById('faster');
slow  = document.getElementById('slower');
image = document.getElementById('gif');
let i = 1;
	// start.disabled = false;
	// slow.disabled  = true;
	// fast.disabled  = true;
let sec = 200;
 start.onclick = function pusk(){
 	timer = setInterval(tim, sec);
// 	start.disabled = true;
// 	slow.disabled  = false;
// 	fast.disabled  = false;
}
// stop.onclick = function pause(){
// 	clearInterval(timer);
// 	start.disabled = false;
// 	slow.disabled  = true;
// 	fast.disabled  = true;
// }
fast.onclick = function faster(){
	clearInterval(timer);
	sec-=100;
	timer = setInterval(tim, sec);
}
// slow.onclick = function slower(){
// 	clearInterval(timer);
// 	sec+=100;
// 	timer = setInterval(tim, sec);
// }

function tim(){
	if (i==13) {
		i=1; 
	}
	gif = new Image();
	gif.scr = "s" + i + ".gif"
	image.scr = gif.src;
	i++;
}
