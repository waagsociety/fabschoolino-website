$(document).ready(function(){
	//init ScrollMagic
	var controller = new ScrollMagic.Controller();
	$('.section').each(function(){
		//build a scene
		var sectionFadeIn = new ScrollMagic.Scene({
			triggerElement: this.children[0],
			reverse: false,
			triggerHook: 0.8
		})
		.setClassToggle(this, 'fade-in') // add class to info
		.addTo(controller);
	});
	//end Section-fadeIn
	//start nav-color
	var navColor = new ScrollMagic.Scene({
		triggerElement: '#info',
		triggerHook: 0.1
	})
	.setClassToggle('#nav ul', 'nav-color') // add class to nav
	.addTo(controller);
});

var acc = document.getElementsByClassName("accordion");
var i;

for (i = 0; i < acc.length; i++) {
	acc[i].onclick = function(){
		this.classList.toggle("active");
		this.nextElementSibling.classList.toggle("show");
	}
}

/*start debug slideshow*/

//var slideIndex = 1;
//showDivs(slideIndex);
//
//function plusDivs(n) {
//    showDivs(slideIndex += n);
//}

function spread(value) {
	return Array.prototype.slice.call(value)
}

!function(containers) {

	//    console.log('containers', container)

	containers.forEach(function(container) {

		console.log(container)
		showDivs(container, 0)

	})


}(spread(document.querySelectorAll('.debug-wrapper')))


function showDivs(container, n) {

	var listElements = spread(container.querySelectorAll('li'))
	var listLast = listElements.length - 1

	listElements.forEach(updateListElement)

	function updateListElement(listItem, index) {
		if (n === index) listItem.style.display = "block"
		else listItem.style.display = "none"
	}


	var buttons = spread(container.querySelectorAll('.prev, .next'))

	function updateButton(button) {

		var disablePrev = n <= 0 && button.classList.contains('prev')
		var disableNext = n >= listLast && button.classList.contains('next')
		console.log(button)
		button.disabled = disablePrev || disableNext

	}
	buttons.forEach(updateButton)
	container.addEventListener('click', function(event) {
		var target = event.target
		while (target !== container) {
			if (target.type === 'button') {
				n += (target.classList.contains('next') ? 1 : -1)
				if (n < 0) n = 0
				else if (n >= listLast) n = listLast
				listElements.forEach(updateListElement)
				buttons.forEach(updateButton)
			}
			target = target.parentElement
		}
	})
}
