// For Nav Bar

window.addEventListener("scroll", function() {
    var nav = document.querySelector("nav");
    var sections = document.querySelectorAll("article");
    var currentSection = "";

    sections.forEach(function(section) {
      var sectionTop = section.offsetTop;
      var sectionHeight = section.clientHeight;

      if (pageYOffset >= (sectionTop - sectionHeight / 3)) {
        currentSection = section.getAttribute("id");
      }
    });

    var currentLink = document.querySelector(".active");
    currentLink.classList.remove("active");

    var newLink = document.querySelector('a[href="#' + currentSection + '"]');
    newLink.classList.add("active");
  });

/////////////////////////

// Home Page

function imgSlider(anything){
    document.querySelector('.drinks').src = anything;
}

function changeCircleColor(color){
    const circle = document.querySelector('.circle');
    const motto = document.querySelector('.motto h2 span')
    const button = document.querySelector('.motto a')
    
    circle.style.background = color;
    motto.style.color = color;
    button.style.background = color;
}

// scroll through different thumb
let currentImageIndex = 0;
const thumbImages = document.querySelectorAll('.thumb li img');

function changeImage() {
  thumbImages[currentImageIndex].click();
  currentImageIndex = (currentImageIndex + 1) % thumbImages.length;
}

// Set interval to change image every 3 seconds
setInterval(changeImage, 3000);

/////////////////////////

// For Menu Div

var menuItems = document.querySelectorAll('.food');
var buttons = document.querySelectorAll('.menu-button');

buttons.forEach(function(button, index) {
  button.addEventListener('click', function() {
    menuItems.forEach(function(item) {
      item.classList.remove('active');
    });

    menuItems[index].classList.add('active');
  });
});

/////////////////////////

function openWebsite() {
    window.open("https://ph.indeed.com/q-cafe-l-manila-jobs.html?vjk=a4637c41a8b45742", "_blank");
  }