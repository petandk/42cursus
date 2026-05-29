<?php
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_FILES['file'])) {
    $uploadDir = '../uploads/';
    $filename = basename($_FILES['file']['name']);
    $targetPath = $uploadDir . $filename;

    if (move_uploaded_file($_FILES['file']['tmp_name'], $targetPath)) {
        // Success
    }
}

header('Location: /tools/uploads.php');
exit;

