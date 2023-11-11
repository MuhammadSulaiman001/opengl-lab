param ([string]$Path)

function Remove-EmptyFolders {
    param (
        [string]$Path
    )

    # Get a list of subfolders in the current directory
    $subfolders = Get-ChildItem -Path $Path -Directory

    # Loop through each subfolder
    foreach ($folder in $subfolders) {
        # Recursively call the function for each subfolder
        Remove-EmptyFolders -Path $folder.FullName

        # Check if the current folder is empty
        if ((Get-ChildItem -Path $folder.FullName).Count -eq 0) {
            Write-Host "Removing empty folder: $($folder.FullName)"
            Remove-Item -Path $folder.FullName
        }
    }
}

Remove-EmptyFolders -Path $Path