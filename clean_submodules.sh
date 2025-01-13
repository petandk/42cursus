
# Find all submodule entries in git config and remove them
git config --file .git/config --list | grep submodule | cut -d. -f2 | while read submodule; do
    echo "Cleaning submodule: $submodule"
    git config --file .git/config --remove-section "submodule.$submodule" || true
    git rm --cached -r "$submodule" || true
    rm -rf ".git/modules/$submodule" || true
done

# Add everything back as regular files
git add .
git commit -m "Convert all submodules to regular directories"
git push

