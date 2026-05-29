	<body<?php echo isset($bodyClass) ? ' class="' . $bodyClass . '"' : ''; ?>>
		<button class="burger-menu" id="burgerMenu" aria-label="Open menu">
			<i class="fa-solid fa-burger"></i>
		</button>
		<aside class="sidebar" id="sidebar">
			<h2>Links &amp; Error Pages</h2>
			<table>
				<tr>
					<th>Type</th>
					<th>Description</th>
					<th>Link</th>
				</tr>
				<tr>
					<td>Main</td>
					<td>Home page</td>
					<td><a href="<?php echo $basePath; ?>index.php">index.php</a></td>
				</tr>
				<tr>
					<td>Main</td>
					<td>Sample image</td>
					<td><a href="<?php echo $basePath; ?>img/sample.png">img/sample.png</a></td>
				</tr>
				<tr>
					<td>Main</td>
					<td>Members</td>
					<td><a href="<?php echo $basePath; ?>members/index.php">members/index.php</a></td>
				</tr>
				<tr>
					<td>CGI</td>
					<td>Python CGI Test</td>
					<td><a href="<?php echo $basePath; ?>tools/python_form.php">python_form.php</a></td>
				</tr>
				<tr>
					<td>CGI</td>
					<td>File Uploads</td>
					<td><a href="<?php echo $basePath; ?>tools/uploads.php">uploads.php</a></td>
				</tr>
				<tr>
					<td>Error</td>
					<td>400 Bad Request</td>
					<td><a href="<?php echo $basePath; ?>errors/400.php">errors/400.php</a></td>
				</tr>
				<tr>
					<td>Error</td>
					<td>401 Unauthorized</td>
					<td><a href="<?php echo $basePath; ?>errors/401.php">errors/401.php</a></td>
				</tr>
				<tr>
					<td>Error</td>
					<td>403 Forbidden</td>
					<td><a href="<?php echo $basePath; ?>errors/403.php">errors/403.php</a></td>
				</tr>
				<tr>
					<td>Error</td>
					<td>404 Not Found</td>
					<td><a href="<?php echo $basePath; ?>errors/404.php">errors/404.php</a></td>
				</tr>
				<tr>
					<td>Error</td>
					<td>405 Method Not Allowed</td>
					<td><a href="<?php echo $basePath; ?>errors/405.php">errors/405.php</a></td>
				</tr>
				<tr>
					<td>Error</td>
					<td>408 Request Timeout</td>
					<td><a href="<?php echo $basePath; ?>errors/408.php">errors/408.php</a></td>
				</tr>
				<tr>
					<td>Error</td>
					<td>413 Payload Too Large</td>
					<td><a href="<?php echo $basePath; ?>errors/413.php">errors/413.php</a></td>
				</tr>
				<tr>
					<td>Error</td>
					<td>414 URI Too Long</td>
					<td><a href="<?php echo $basePath; ?>errors/414.php">errors/414.php</a></td>
				</tr>
				<tr>
					<td>Error</td>
					<td>415 Unsupported Media Type</td>
					<td><a href="<?php echo $basePath; ?>errors/415.php">errors/415.php</a></td>
				</tr>
				<tr>
					<td>Error</td>
					<td>500 Internal Server Error</td>
					<td><a href="<?php echo $basePath; ?>errors/500.php">errors/500.php</a></td>
				</tr>
				<tr>
					<td>Error</td>
					<td>501 Not Implemented</td>
					<td><a href="<?php echo $basePath; ?>errors/501.php">errors/501.php</a></td>
				</tr>
				<tr>
					<td>Error</td>
					<td>502 Bad Gateway</td>
					<td><a href="<?php echo $basePath; ?>errors/502.php">errors/502.php</a></td>
				</tr>
				<tr>
					<td>Error</td>
					<td>503 Service Unavailable</td>
					<td><a href="<?php echo $basePath; ?>errors/503.php">errors/503.php</a></td>
				</tr>
				<tr>
					<td>Error</td>
					<td>504 Gateway Timeout</td>
					<td><a href="<?php echo $basePath; ?>errors/504.php">errors/504.php</a></td>
				</tr>
			</table>
		</aside>

