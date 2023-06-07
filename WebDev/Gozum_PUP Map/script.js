const map = document.querySelector('map[name="pup-map"]');
const tooltip = document.querySelector("#tooltip");
const tooltipImage = tooltip.querySelector("#image");
const tooltipName = tooltip.querySelector("#name");
const tooltipDescription = tooltip.querySelector("#description");

const areas = map.querySelectorAll("& > area");

for (const area of areas) {
  const details = coords.find((place) => place.id == area.id);

  area.addEventListener("mouseover", () => {
    setTooltip(details);
    showTooltip();
  });

  area.addEventListener("mouseout", () => {
    setTooltip(details);
    hideTooltip();
  });
}

document.body.addEventListener("mousemove", (event) => {
  tooltip.style.setProperty("--mouseX", event.clientX + "px");
  tooltip.style.setProperty("--mouseY", event.clientY + "px");
});

function setTooltip(details) {
  if (details.imagePath) {
    tooltipImage.src = details.imagePath;
    tooltipImage.style.setProperty("display", "block");
  } else {
    tooltipImage.src = "";
    tooltipImage.style.setProperty("display", "none");
  }

  tooltipName.textContent = details.title;
  tooltipDescription.textContent = details.description;
}

function removeTooltip() {
  tooltipImage.src = "";
  tooltipName.textContent = "";
  tooltipDescription.textContent = "";
}

function showTooltip() {
  tooltip.style.setProperty("display", "block");
}

function hideTooltip() {
  tooltip.style.setProperty("display", "none");
}
