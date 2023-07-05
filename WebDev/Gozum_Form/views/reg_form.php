<?php
    session_start();

    include("register.php");

    if(isset($_SESSION['user'])) {
        header("Location: home.php");
        exit();
    }
?>

<!DOCTYPE html>

<html>
    <head>
        <meta charset="utf-8" />
        <meta http-equiv="X-UA-Compatible" content="IE-edge" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Aerith | Registration Form</title>
        <link rel="icon" href="../img/Logo.png" type="image/x-icon"/>
        <link href="../css/reg.css" rel="stylesheet">
    </head>

    <body>
        <form action="register.php" method="POST" class = "contents">

            <!-- left -->
            <div class = "left-box">
                <header>
                    <h1><a href="../index.php" class="toHome">aerith.</a></h1>
                    <h2>Club Membership</h2>
                    <p>Complete the form below to sign up for our membership service.</p>
                    <p><br/>Already a member? <a href="login_form.php" id="register">Login Here</a></p>
                </header>

                <!-- Progress Bar -->
                <div class="progress-bar">
                    <div class="progress" id="progress"></div>

                    <div class = "progress-step progress-step-active" data-title = "Personal information"></div>
                    <div class = "progress-step" data-title = "Permanent Address"></div>
                    <div class = "progress-step" data-title = "Additional information"></div>
                    <div class = "progress-step" data-title = "Rules and Privacy"></div>
                </div>  
            </div>

            <!-- right -->
            <div class="right-box">

                <!-- Personal Info -->
                <div class="form-step form-step-active">
                    <div class="intro">
                        <h1>Your Personal Information</h1>
                        <p>Help us get to know you better by providing your personal details. Your information will be kept confidential and used solely for the purpose of this registration.</p>
                        <i><p> Note: Input n/a if not applicable </p></i>
                    </div>
                
                    <div class="input-group">
                        <input type="text" name="first-name" id="first-name" required>
                        <label class="label first">First Name</label>
                        <input type="text" name="last-name" id="last-name" required>
                        <label class="label">Last Name</label>
                        <input type="text" name="middle-name" id="middle-name" required>
                        <label class="label first">Middle Name</label>
                        <input type="text" name="gender" id="gender" required>
                        <label class="label">Gender</label>
                    </div>
                              
                    <div class="input-group">
                        <input type="text" name="number" id="number" required>
                        <label class="label first">Phone Number</label>
                        <input type="text" name="email" id="email" required>
                        <label class="label">E-mail Address</label>
                    </div>

                    <div class="input-group birthday">
                        <p style="opacity: 1;">Birthday:</p>
                        <select id ="month" name = "mm" onchange="change_month(this)">
                            <option value="" disabled selected>Month</option>
                        </select>
                        <select id ="day" name = "dd" onchange="change_year(this)">
                            <option value="" disabled selected>Day</option>
                        </select>
                        <select id ="year" name = "yyyy" onchange="change_year(this)">
                            <option value="" disabled selected>Year</option>
                        </select>
                    </div>
                
                    <div>
                        <input type="reset" class="btn btn-clear" value="Clear">
                    </div>

                    <div>
                        <input type="button" class="btn btn-next" value="Next">
                    </div>
                </div>

                <!-- Home Address -->
                <div class="form-step">
                    <div class="intro">
                        <h1>Your Home Address</h1>
                        <p>Please provide your current residential address for communication and correspondence purposes.</p>
                        <i><p> Note: Input n/a if not applicable </p></i>
                    </div>
                
                    <div class="input-group">
                        <input type = "text" name = "address" id = "address" required> <label class = "label first">Unit no/House no</label>
                        <input type = "text" name = "street" id = "street" required> <label class = "label">Street</label>
                        <input type = "text" name = "subd" id = "subd" required> <label class = "label first">Village/Subdivision</label>
                        <select name="region" id="region" required>
                            <option value="" disabled selected>Select Region</option>
                        </select>
                        <select name="province" id="province" required>
                            <option value="" disabled selected>Select Province</option>
                        </select>
                        <select name="municipality" id="municipality" required>
                            <option value="" disabled selected>Select Municipality</option>
                        </select>
                        <select name="barangay" id="barangay" required>
                            <option value="" disabled selected>Select Barangay</option>
                        </select>
                        <input type = "text" name = "zip" id = "zip" required> <label class = "label">Zip Code</label>
                    </div>

                    <div>
                        <input type="reset" class="btn btn-clear" value="Clear">
                    </div>

                    <div>
                        <input type="button" class="btn btn-next" value="Next">
                        <input type="button" class="btn btn-prev" value="Previous">
                    </div>
                </div>

                <!-- Add Info -->
                <div class="form-step">
                    <div class="intro">
                        <h1>Additional Information</h1>
                    </div>
                        
                    <div style = "display: flex;">
                        <div class="input-group" style="width: 50%;">
                            <p class = "radio-grp">Membership Type</p>
                            <div class = "radio-adjust"><input type="radio" name = "membership" value = "standard"> <label class = "radio-lbl">Standard</label><br></div>
                            <div class = "radio-adjust"><input type="radio" name = "membership" value = "premium"> <label class = "radio-lbl">Premium</label><br></div>
                            <div class = "radio-adjust"><input type="radio" name = "membership" value = "ultimate"> <label class = "radio-lbl">Ultimate</label></div>
                        </div>

                        <div class="input-group">
                            <p class = "radio-grp">Preferred way to contact</p>
                            <div class = "radio-adjust"><input type="radio" name = "prefContact" value = "standard"> <label class = "radio-lbl">Phone</label><br></div>
                            <div class = "radio-adjust"><input type="radio" name = "prefContact" value = "premium"> <label class = "radio-lbl">Email</label><br></div>
                            <div class = "radio-adjust"><input type="radio" name = "prefContact" value = "ultimate"> <label class = "radio-lbl">Any</label></div>
                        </div>
                    </div>
                    
                    <div style = "display: flex; margin-top: 5vh;">
                        <div class="input-group" style="width: 50%;">
                            <p class = "radio-grp">Where did you hear about us?</p>
                            <div class = "checkbox"><input type="checkbox" name = "recom[]" value = "friend"> <label class = "radio-lbl">Friend</label><br></div>
                            <div class = "checkbox"><input type="checkbox" name = "recom[]" value = "Google"> <label class = "radio-lbl">Google</label><br></div>
                            <div class = "checkbox"><input type="checkbox" name = "recom[]" value = "Blog Post"> <label class = "radio-lbl">Blog Post</label><br></div>
                            <div class = "checkbox"><input type="checkbox" name = "recom[]" value = "News Article"> <label class = "radio-lbl">News Article</label><br></div>
                            <div class = "checkbox"><input type="checkbox" name = "recom[]" value = "Other"> <label class = "radio-lbl">Other</label><br></div>
                        </div>

                        <div class="input-group" style="width: 50%;">
                            <p class = "radio-grp">Account Password</p>
                            <input type="password" placeholder="******" name="password" id="password" required>
                            <ul>
                                <li>8 characters or more</li>
                                <li>contain 1 uppercase and 1 lowercase</li> 
                                <li>contain atleast 1 digit</li>
                            </ul>
                        </div>
                    </div>
                    
                    <div style="clear: both;">
                        <input type="reset" class="btn btn-clear" value="Clear">
                    </div>

                    <div>
                        <input type="button" class="btn btn-next" value="Next">
                        <input type="button" class="btn btn-prev" value="Previous">
                    </div>
                </div>

                <!-- Rules and Privacy -->
                <div class="form-step">
                    <div class="intro" style = "margin-bottom: 15px;">
                        <h1>Rules and Privacy</h1>
                    </div>
                        
                    <div class="input-group" style = "margin-top: 40px;">
                        <p class = "radio-grp">Membership Rules</p>
                        <p style = "margin-left: 25px; margin-right: 20px;">
                            1. Membership is available to anyone 18 years of age or older.<br/><br/>
                            2. You promise NOT to use to conduct any fraudulent or business activity or have more than one Member Account at any time.
                        </p>
                        <div class = "req-checkbox"><input type="checkbox" name="memRules" value="1" required> I have read, understood, and accepted the rules for membership.</div>
                    </div>

                    <div class="input-group" style = "margin-top: 40px;">
                        <p class = "radio-grp">Privacy Policy</p>
                        <p style = "margin-left: 25px; margin-right: 20px;">
                            Please reach out and read our Privacy Policy in order to understand how your information is used and shared, and check below if you accept the policy.
                        </p>
                        <div class = "req-checkbox"><input type="checkbox" name="memPrivacy" value="1" required> I have read, understood, and accepted the PRIVACY POLICY for membership.</div>
                    </div>
                        
                    <div style="margin-top: 15vh;">
                        <input type="reset" style = "margin-top: 2px;" class="btn btn-clear" value="Clear">
                    </div>

                    <div>
                        <input type="button" style = "margin-top: 2px;" class="btn btn-next" value="Next">
                        <input type="button" style = "margin-top: 2px;" class="btn btn-prev" value="Previous">
                    </div>
                </div>

                <!-- Done -->
                <div class="form-step">
                    <div class="end">
                        <h1> Thank You for Completing the Membership Registration Form!</h1>
                        <p> Once you submit your application, we will contact you shortly to complete your membership application. 

                        <br/><br/>If you have any further questions or require additional information, please feel free to reach out to us. We look forward to the possibility of welcoming you to our team.</p>
                    </div>
                        
                    <div style="margin-top: 15vh;">
                        <input type="submit" style = "margin-top: 2px;" class="btn btn-submit" value="Submit" onclick="success()">
                        <input type="button" style = "margin-top: 2px;" class="btn btn-prev" value="Previous">
                    </div>
                </div>
            </div>
        </form>
        
        <script src="../scripts/registration_form.js"></script>
        <script src="../scripts/region.js"></script>
        <script src="../scripts/province.js"></script>
        <script src="../scripts/municipality.js"></script>
        <script src="../scripts/barangay.js"></script>
    
    </body>
</html>