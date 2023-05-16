// const prevBtns = document.querySelectorAll(".btn-prev");
// const nextBtns = document.querySelectorAll(".btn-next");
// const progress = document.getElementById("progress");
// const formSteps = document.querySelectorAll(".form-step");
// const progressSteps = document.querySelectorAll(".progress-step");

// let formStepsNum = 0;

// nextBtns.forEach((btn) => {
//     btn.addEventListener("click", () => {
//         formStepsNum++;
//         updateFormSteps();
//         updateProgressbar();
//     })
// })

// prevBtns.forEach(btn => {
//     btn.addEventListener("click", () => {
//         formStepsNum--;
//         updateFormSteps();
//         updateProgressbar();
//     })
// })

// function updateFormSteps(){

//     formSteps.forEach((formStep) => {
//         formStep.classList.contains("form-steps-active") ==
//         formStep.classList.remove("form-step-active");
//     })

//     formSteps[formStepsNum].classList.add("form-step-active");
// }

// function updateProgressbar(){
//     progressSteps.forEach((progressStep, index) => {
//         if(index < formStepsNum + 1){
//             progressStep.classList.add("progress-step-active");
//         } else {
//             progressStep.classList.remove("progress-step-active");
//         }
//     });

//     const progressActive = document.querySelectorAll(".progress-step-active");

//     progress.style.height = ((progressActive.length - 1) / (progressSteps.length - 1) * 100 + "%");

// }

const prevBtns = document.querySelectorAll(".btn-prev");
const nextBtns = document.querySelectorAll(".btn-next");
const progress = document.getElementById("progress");
const formSteps = document.querySelectorAll(".form-step");
const progressSteps = document.querySelectorAll(".progress-step");

let formStepsNum = 0;

// Form

nextBtns.forEach((btn) => {
  btn.addEventListener("click", () => {
    if (validateForm()) {
      formStepsNum++;
      updateFormSteps();
      updateProgressbar();
    }
  });
});

prevBtns.forEach((btn) => {
  btn.addEventListener("click", () => {
    formStepsNum--;
    updateFormSteps();
    updateProgressbar();
  });
});

function updateFormSteps() {
  formSteps.forEach((formStep) => {
    formStep.classList.remove("form-step-active");
  });

  formSteps[formStepsNum].classList.add("form-step-active");
}

// Update Progress bar

function updateProgressbar() {
  progressSteps.forEach((progressStep, index) => {
    if (index < formStepsNum + 1) {
      progressStep.classList.add("progress-step-active");
    } else {
      progressStep.classList.remove("progress-step-active");
    }
  });

  const progressActive = document.querySelectorAll(".progress-step-active");

  progress.style.height =
    ((progressActive.length - 1) / (progressSteps.length - 1)) * 100 + "%";
}

// Check if all fields have been filled
function validateForm() {
    const currentFormStep = formSteps[formStepsNum];
    const inputs = currentFormStep.querySelectorAll("input, textarea, select");
    const radioGroups = currentFormStep.querySelectorAll("input[type='radio']");
  
    for (let i = 0; i < inputs.length; i++) {
      if (!inputs[i].value) {
        alert("Please fill in all fields before proceeding.");
        return false;
      }
    }
  
    for (let i = 0; i < radioGroups.length; i++) {
      const radioGroup = radioGroups[i].name;
      const checkedRadio = currentFormStep.querySelector(`input[name='${radioGroup}']:checked`);
      if (!checkedRadio) {
        alert("Please select an option for all radio button groups.");
        return false;
      }
    }
  
    return true;
}

//Once form is submitted

function success(){
    alert("Form Successfully Submitted");
}


// For selecting address

document.addEventListener('DOMContentLoaded', () => {
    const regionSelect = document.getElementById('region');
    const provinceSelect = document.getElementById('province');
    const municipalitySelect = document.getElementById('municipality');
    const barangaySelect = document.getElementById('barangay');
  
    function populateSelect(selectElement, data, keyId, keyName, defaultOption) {
      selectElement.innerHTML = '';
  
      if (defaultOption) {
        const defaultOptionElement = document.createElement('option');
        defaultOptionElement.value = '';
        defaultOptionElement.textContent = defaultOption;
        selectElement.appendChild(defaultOptionElement);
      }
  
      for (let i = 0; i < data.length; i++) {
        const item = data[i];
        const option = document.createElement('option');
        option.value = item[keyId];
        option.textContent = item[keyName];
        selectElement.appendChild(option);
      }
    }
  
    populateSelect(regionSelect, regionData, 'region_id', 'region_name', 'Select Region');
  
    regionSelect.addEventListener('change', (event) => {
      const selectedRegion = event.target.value;
      const provinces = provinceData.filter(province => province.region_id === parseInt(selectedRegion));
      populateSelect(provinceSelect, provinces, 'province_id', 'province_name', 'Select Province');
      populateSelect(municipalitySelect, [], 'municipality_id', 'municipality_name', 'Select Municipality');
      populateSelect(barangaySelect, [], 'barangay_id', 'barangay_name', 'Select Barangay');
    });
  
    provinceSelect.addEventListener('change', (event) => {
      const selectedProvince = event.target.value;
      const municipalities = municipalityData.filter(municipality => municipality.province_id === parseInt(selectedProvince));
      populateSelect(municipalitySelect, municipalities, 'municipality_id', 'municipality_name', 'Select Municipality');
      populateSelect(barangaySelect, [], 'barangay_id', 'barangay_name', 'Select Barangay');
    });
  
    municipalitySelect.addEventListener('change', (event) => {
      const selectedMunicipality = event.target.value;
      const barangays = barangayData.filter(barangay => barangay.municipality_id === parseInt(selectedMunicipality));
      populateSelect(barangaySelect, barangays, 'barangay_id', 'barangay_name', 'Select Barangay');
    });
  });
  