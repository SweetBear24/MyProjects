image1 = document.getElementById('image1');
image2 = document.getElementById('image2');

let temp;
function set_image() {
	temp = image1.src;
	image1.src = image2.src;
	image2.src = temp;
}