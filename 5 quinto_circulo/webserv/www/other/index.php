<?php
$serverName = $_SERVER['SERVER_NAME'] ?? 'unknown';
$serverAddr = $_SERVER['SERVER_ADDR'] ?? 'unknown';
$serverPort = $_SERVER['SERVER_PORT'] ?? 'unknown';
$serverSoftware = $_SERVER['SERVER_SOFTWARE'] ?? 'unknown';
$requestMethod = $_SERVER['REQUEST_METHOD'] ?? 'unknown';
$requestUri = $_SERVER['REQUEST_URI'] ?? 'unknown';
$remoteAddr = $_SERVER['REMOTE_ADDR'] ?? 'unknown';
$hostname = gethostname() ?: 'unknown';
$now = date('Y-m-d H:i:s');
$phpVersion = phpversion();
$pid = getmypid();
$os = php_uname('s') . ' ' . php_uname('r');
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Color Pulse - Multi Server Test</title>
    <link rel="stylesheet" href="css/style.css">
</head>
<body>
    <main class="page">
        <section class="hero card">
            <p class="chip">PHP Multi-Server Test</p>
            <h1>Color Pulse Playground</h1>
            <p class="lead">
                If you can see this page, this server is responding correctly.
                Use the data below to distinguish instances running at the same time.
            </p>
        </section>

        <section class="grid">
            <article class="card stat">
                <h2>Servidor</h2>
                <ul>
                    <li><strong>Hostname:</strong> <?php echo htmlspecialchars($hostname); ?></li>
                    <li><strong>Server Name:</strong> <?php echo htmlspecialchars($serverName); ?></li>
                    <li><strong>Software:</strong> <?php echo htmlspecialchars($serverSoftware); ?></li>
                    <li><strong>Address:</strong> <?php echo htmlspecialchars($serverAddr . ':' . $serverPort); ?></li>
                </ul>
            </article>

            <article class="card stat">
                <h2>Request</h2>
                <ul>
                    <li><strong>Method:</strong> <?php echo htmlspecialchars($requestMethod); ?></li>
                    <li><strong>URI:</strong> <?php echo htmlspecialchars($requestUri); ?></li>
                    <li><strong>Client IP:</strong> <?php echo htmlspecialchars($remoteAddr); ?></li>
                    <li><strong>Time:</strong> <?php echo htmlspecialchars($now); ?></li>
                </ul>
            </article>

            <article class="card stat">
                <h2>Runtime</h2>
                <ul>
                    <li><strong>PHP:</strong> <?php echo htmlspecialchars($phpVersion); ?></li>
                    <li><strong>Process PID:</strong> <?php echo htmlspecialchars((string)$pid); ?></li>
                    <li><strong>OS:</strong> <?php echo htmlspecialchars($os); ?></li>
                    <li><strong>SAPI:</strong> <?php echo htmlspecialchars(PHP_SAPI); ?></li>
                </ul>
            </article>
        </section>
    </main>
</body>
</html>
