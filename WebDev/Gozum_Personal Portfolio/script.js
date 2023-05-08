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

window.addEventListener("scroll", reveal);

function reveal(){
  var reveals = document.querySelectorAll(".reveal");

  for(var i = 0; i < reveals.length; i++){
    var windowheight = window.innerHeight;
    var revealtop = reveals[i].getBoundingClientRect().top;
    var revealpoint = 150;

    if(revealtop < windowheight - revealpoint){
      reveals[i].classList.add("active");
    } else {
      reveals[i].classList.remove("active");
    }
  }
}