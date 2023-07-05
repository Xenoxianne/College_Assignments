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
    const checkGroups = currentFormStep.querySelectorAll("input[type='checkbox']");
    
    var error = '';

    const name = document.getElementById('first-name').value + ' ' + document.getElementById('middle-name').value + ' ' + document.getElementById('last-name').value;
    const gender = document.getElementById('gender').value;
    const number = document.getElementById('number').value;
    const email = document.getElementById('email').value;
    const address = document.getElementById('address').value;
    const street = document.getElementById('street').value;
    const subd = document.getElementById('subd').value;
    const zip = document.getElementById('zip').value;
    const password = document.getElementById('password').value;

    // no input //
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
  
      for (let i = 0; i < checkGroups.length; i++) {
        const checkGroup = checkGroups[i].name;
        const checkedBox = currentFormStep.querySelector(`input[name='${checkGroup}']:checked`);
        if (!checkedBox) {
          alert("Please select an option for  the checkbox/s.");
          return false;
        }
      }

    // input
    // Validate name
    var regex_letters = /^[a-zA-Z\s]+$/;
    var regex_num = /^\d{1,11}$/;
    var regex_zip = /^\d{4}$/;
    var regex_address = /^[a-zA-Z0-9\s\.,-]+$/;
    var regex_email = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;

    if(formStepsNum == 0){
        if (!regex_letters.test(name)) {
            error = 'name';
        } else if(!regex_letters.test(gender)) {
            error = 'gender';
        } else if (!regex_num.test(number) || number.length < 11) {
            error = 'contact number';
        } else if(!regex_email.test(email)){
            error = 'email';
        }
    }else if(formStepsNum == 1){
        if (!regex_address.test(address)) {
            error = 'address';
        } else if (!regex_address.test(street)) {
            error = 'street';
        } else if (!regex_address.test(subd)) {
            error = 'subd';
        } else if (!regex_zip.test(zip) || zip.length < 4) {
            error = 'zip';
        } 
    }else if(formStepsNum == 2){
      if (password.length < 8) {
        alert("Password should be at least 8 characters long.");
        return false; // Invalid input
      } else if (!/[a-z]/.test(password)) {
        alert("Password should contain at least one lowercase letter.");
        return false; // Invalid input
      } else if (!/[A-Z]/.test(password)) {
        alert("Password should contain at least one uppercase letter.");
        return false; // Invalid input
      } else if (!/[0-9]/.test(password)) {
        alert("Password should contain at least one digit.");
        return false; // Invalid input
      }
    }

    // Check for errors
    switch (error) {
        case 'name':
        case 'gender':
            alert("Invalid " + error + ". Only letters and whitespaces are allowed.");
            return false; // Invalid input
        case 'contact number':
            alert("Invalid " + error + ". Please enter a valid 11-digit contact number starting with '09'.");
            return false; // Invalid input
        case 'email':
            alert("Invalid email address. Please enter a valid email.");
            return false; // Invalid input
        case 'address':
        case 'street':
        case 'subd':
        case 'zip':
            alert("Invalid " + error + ". Please enter a valid address.");
            return false; // Invalid input
    }

    return true;
}

//Once form is submitted
function success(){
    alert("Form Successfully Submitted");
}

// For birthday
var Days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]; // index => month [0-11]

// Populate the month dropdown with options
var monthDropdown = document.getElementById("month");
var months = [
  "January", "February", "March", "April", "May", "June", "July",
  "August", "September", "October", "November", "December"
];
for (var i = 0; i < months.length; i++) {
  var option = document.createElement("option");
  option.text = months[i];
  monthDropdown.add(option);
}

// Populate the day dropdown with options
var dayDropdown = document.getElementById("day");
for (var i = 1; i <= 31; i++) {
  var option = document.createElement("option");
  option.text = i;
  dayDropdown.add(option);
}

// Populate the year dropdown with options
var yearDropdown = document.getElementById("year");
var currentYear = new Date().getFullYear();
for (var i = currentYear; i >= currentYear - 100; i--) {
  var option = document.createElement("option");
  option.text = i;
  yearDropdown.add(option);
}

// Handle the onchange event for month dropdown
function change_month(select) {
  var selectedMonth = select.value;
  console.log("Selected Month: " + selectedMonth);
}

// Handle the onchange event for day and year dropdowns
function change_year(select) {
  var selectedDay = dayDropdown.value;
  var selectedYear = yearDropdown.value;
  console.log("Selected Day: " + selectedDay);
  console.log("Selected Year: " + selectedYear);
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
  