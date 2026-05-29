<?php
$pageTitle = 'File Uploads';
$basePath = '../';
include '../includes/head.php';
include '../includes/sidebar.php';
?>
		<div class="container">
			<h1>File Uploads</h1>

			<h2>Upload a file</h2>
			<form action="upload_handler.php" method="POST" enctype="multipart/form-data">
				<label for="file" class="btn">Choose File</label>
				<input type="file" id="file" name="file" hidden required>
				<input type="submit" value="Upload File">
			</form>
            <br />
			<h2>Uploaded files</h2>
			<ul>
<?php
$uploadDir = '../uploads/';
if (is_dir($uploadDir)) {
    $files = array_diff(scandir($uploadDir), array('.', '..'));
    if (count($files) > 0) {
        foreach ($files as $file) {
            $filePath = $uploadDir . $file;
            $fileSize = filesize($filePath);
            if ($fileSize < 1024) {
                $sizeStr = $fileSize . ' B';
            } elseif ($fileSize < 1048576) {
                $sizeStr = round($fileSize / 1024, 1) . ' KB';
            } else {
                $sizeStr = round($fileSize / 1048576, 1) . ' MB';
            }
            echo "\t\t\t\t<li>\n";
            echo "\t\t\t\t\t<strong>$file</strong> ($sizeStr)\n";
            echo "\t\t\t\t\t<form action=\"delete_file.php\" method=\"POST\" style=\"display:inline;\">\n";
            echo "\t\t\t\t\t\t<input type=\"hidden\" name=\"file\" value=\"$file\">\n";
            echo "\t\t\t\t\t\t<input type=\"submit\" value=\"Delete\" onclick=\"return confirm('Delete $file?')\">\n";
            echo "\t\t\t\t\t</form>\n";
            echo "\t\t\t\t</li>\n";
        }
    } else {
        echo "\t\t\t\t<li><em>No files uploaded yet.</em></li>\n";
    }
} else {
    echo "\t\t\t\t<li><em>Uploads directory not found.</em></li>\n";
}
?>
			</ul>
<?php include '../includes/return_button.php'; ?>
		</div>
		<script src="<?php echo $basePath; ?>js/script.js">
		</script>
	</body>
</html>

