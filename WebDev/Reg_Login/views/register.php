<?php

    include("../database/database.php");

    if($_SERVER["REQUEST_METHOD"] == "POST"){

        $FirstName = $_POST['first-name'];
        $LastName = $_POST['last-name'];
        $MiddleName = $_POST['middle-name'];
        $Name = $FirstName . ' ' . $MiddleName . ' ' . $LastName ;

        $Gender = $_POST['gender'];
        $PhoneNumber = $_POST['number'];
        $Email = $_POST['email'];

        $Month = $_POST['mm'];
        $Day = $_POST['dd'];
        $Year = $_POST['yyyy'];
        $Birthday = $Month . ' ' .  $Day . ' ' . $Year;

        $Address = $_POST['address'];
        $Street = $_POST['street'];
        $Subdivision = $_POST['subd'];
        $Region = $_POST['region'];
        $Province = $_POST['province'];
        $Municipality = $_POST['municipality'];
        $Barangay = $_POST['barangay'];
        $ZipCode = $_POST['zip'];
        $Membership = $_POST['membership'];
        $Contact = $_POST['prefContact'];

        $Recommend = $_POST['recom'];
        $Recommendations = implode(", ", $Recommend); // Convert the array to a comma-separated string
        
        $Password = $_POST['password'];
        $hash = password_hash($Password, PASSWORD_DEFAULT);

        $sql = "INSERT INTO registration (name, gender, number, email, birthday, address, street, subd, region, province, municipality, barangay, zip, membership, prefContact, recom, password) VALUES ('$Name', '$Gender', '$PhoneNumber', '$Email', '$Birthday', '$Address', '$Street', '$Subdivision', '$Region', '$Province', '$Municipality', '$Barangay', '$ZipCode', '$Membership', '$Contact', '$Recommendations', '$hash')";

        if (mysqli_query($connection, $sql)) {
            header("Location: login_form.php");
            exit();
        } else {
            $Error = "Error: " . $sql . "<br>" . mysqli_error($connection);
        }

        // Close the database connection
        mysqli_close($connection);
    }

?>