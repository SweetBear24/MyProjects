image1 = document.getElementById('Korra');
image2 = document.getElementById('Aang');

let tepm;
function set_image() {
	temp = image1.src;
	image1.src = image2.src;
	image2.src = temp;
}