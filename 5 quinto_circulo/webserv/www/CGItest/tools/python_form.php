<?php
$pageTitle = 'Python CGI Test';
$basePath = '../';
include '../includes/head.php';
include '../includes/sidebar.php';
?>
		<div class="container">
			<h1>Python CGI Test</h1>
			<p>Test form to send data to the Python CGI script.</p>

			<form action="../python/test.py" method="POST">
				<label for="name">Name:</label>
				<input type="text" id="name" name="name" placeholder="Your name" required>
				<br><br>
				<label for="message">Message:</label>
				<textarea id="message" name="message" placeholder="Write a message..." rows="4" cols="50"></textarea>
				<br><br>
				<input type="submit" value="Send to Python CGI">
			</form>
<?php include '../includes/return_button.php'; ?>
		</div>
		<script src="<?php echo $basePath; ?>js/script.js">
		</script>
	</body>
</html>
