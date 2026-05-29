<?php
$pageTitle = 'CGItest';
$basePath = '';
include 'includes/head.php';
include 'includes/sidebar.php';
?>
		<div class="container">
			<h1>Simple HTML homepage</h1>
			<p>Welcome to the web server test page.</p>

			<div class="image-row">
				<div class="image-col">
					<h2>Sample image from file</h2>
					<img class="border" src="<?php echo $basePath; ?>img/sample.png" alt="Sample image from file" width="600" height="300">
				</div>
				<div class="image-col">
					<h2>Sample image from link</h2>
					<img class="border" src="https://picsum.photos/600/300?grayscale" alt="Sample image from link" width="600" height="300">
				</div>
			</div>
		</div>
		<script src="<?php echo $basePath; ?>js/script.js">
		</script>
	</body>
</html>
