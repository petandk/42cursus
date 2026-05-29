<?php
$pageTitle = 'Members';
$basePath = '../';
$bodyClass = 'members-page';
include '../includes/head.php';
include '../includes/sidebar.php';
?>
		<div class="container">
			<h1>Project Members</h1>
			<table>
				<thead>
					<tr>
						<th>Intra 42 name</th>
						<th>GitHub Profile</th>
					</tr>
				</thead>
				<tbody>
					<tr>
						<td>rmanzana</td>
						<td><a href="https://github.com/petandk" target="_blank">github.com/petandk</a></td>
					</tr>
					<tr>
						<td>pmorello</td>
						<td><a href="https://github.com/Pmoreamo" target="_blank">github.com/Pmoreamo</a></td>
					</tr>
					<tr>
						<td>jaacosta</td>
						<td><a href="https://github.com/stick0789" target="_blank">github.com/stick0789</a></td>
					</tr>
				</tbody>
			</table>
<?php include '../includes/return_button.php'; ?>
		</div>
		<script src="<?php echo $basePath; ?>js/script.js">
		</script>
	</body>
</html>
