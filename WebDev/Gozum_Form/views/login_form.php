<?php 
    session_start();

	include('../database/database.php');

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
        <title>Aerith | Login Form</title>
		<link rel="icon" href="../img/Logo.png" type="image/x-icon"/>
        <link href="../css/login.css" rel="stylesheet"/>
	</head>

	<body>
		<form action="<?php htmlspeciaLchars($_SERVER["PHP_SELF"])?>" method="POST" onSubmit="return validate();" class="contents">
			<!-- Buttons -->
			<div class="intro">
				<h2><a href="../index.php" class="toHome">aerith.</a></h2>
				<h1>Login</h1>
			</div>

			<!-- Show error -->
			<?php if(isset($_GET['error'])) { ?>
					<p class = "error"> <?php echo $_GET['error']; ?> </p>
			<?php } ?>
		
			<!-- Form -->
			<div class="input-group">
				<input type="text" name="email" id="email" required>
				<label class="label first">Email</label>
				<input type="password" name="password" id="password" required>
				<label class="label">Password</label>
			</div>
						
			<!-- Buttons -->
			<input type="submit" value="Login" class="btn">

			<!-- Sign Up -->
			<div class="register">
				<p>Not a member? <a href="reg_form.php">Signup Now</a></p>
			</div>
		</form>

	</body>
</html>

<?php 
	if($_SERVER["REQUEST_METHOD"] == "POST"){

		$email = mysqli_real_escape_string($connection, $_POST['email']);
		$PTpassword = mysqli_real_escape_string($connection, $_POST['password']);

		$query = "SELECT password FROM registration WHERE email = '$email'";
		$result = mysqli_query($connection, $query);

		if(mysqli_num_rows($result) > 0){   
			$row = mysqli_fetch_assoc($result);
			$CTpassword = $row['password'];
			$_SESSION['email'] = $email;

			// Check if entered plaintext password is same with ciphertext
			if(password_verify($PTpassword, $CTpassword)){
				$_SESSION['user'] = true;
				header("Location: home.php");
			} else{
				header("Location: login_form.php?error=Incorrect Password");
				exit();
			}

		}else{
			header("Location: login_form.php?error=Account not found");
			exit();
		}
	}

    mysqli_close($connection);
?>