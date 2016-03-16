<?php 

//connection data
	$servername = "localhost";
	$username = "root";
	$password = "";
	$database = "ArduinoTest";

//arduino data
	$barcode = $_GET["barcode"];

	//Create connection 
	$conn = new mysqli($servername, $username, $password, $database);

	//Check connection 
	if($conn -> connect_error){
		die("Connection failed: " . $conn-> connect_error);
	}
	echo "Connected successfully,\n";

	//querys 
	$query_select = "SELECT checked FROM ticket WHERE barcode = " . $barcode;
	$query_update = "UPDATE ticket SET checked = 0 WHERE barcode = " . $barcode;

	//Execute the select and save the result into $result
	$result = $conn -> query($query_select);

	//Check if we have data 
	if($result -> num_rows > 0){
		$row = $result -> fetch_assoc();
		$var = $row["checked"];

		//if is a no used barcode, pass and update the database
		if($var == 1){
			$update = $conn -> query($query_update);
			echo "Checked " . $var;
		}else{
			echo "You cannot use the same barcode twise." . $var;
		}

	}else{
		echo "We cannot find this barcode.";
	}

	//close connection
	$conn -> close();
?>