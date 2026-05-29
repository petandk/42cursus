<?php
$uploadDir = '../uploads/';

if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['file'])) {
    $file = basename($_POST['file']);
    $filePath = $uploadDir . $file;

    if (file_exists($filePath)) {
        unlink($filePath);
    }
}

header('Location: /tools/uploads.php');
exit;

