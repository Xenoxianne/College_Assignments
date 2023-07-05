function validate() {
    var valid = true;
    document.getElementById("user_info").innerHTML = "";
    document.getElementById("password_info").innerHTML = "";
    
    var userName = document.getElementById("user_name").value;
    var password = document.getElementById("password").value;
    if(userName == "") 
    {
        document.getElementById("user_info").innerHTML = "required";
        valid = false;
    }
    if(password == "") 
    {
        document.getElementById("password_info").innerHTML = "required";
        valid = false;
    }
    return valid;
}


// <!-- Show error -->
// <?php if(isset($_GET['error'])) { ?>
//     <p class="col-lg-7 mx-auto p-2" style="background-color: #F2DEDE; color: #A94442"> <?php echo $_GET['error']; ?> </p>
// <?php } ?>