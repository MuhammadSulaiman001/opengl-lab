param([string]$projectDir, [string]$outputPath);

# logs
# D:\_ ite\_ code\.muhammadsulaiman001\opengl-lab\OpenGLab\LabDemos
Write-Host "ProjectDir = $projectDir"
# D:\_ ite\_ code\.muhammadsulaiman001\opengl-lab\OpenGLab\LabDemos\Debug
Write-Host "OutputPath = $outputPath"

# Copy all dependencies to be able to run the application via .exe double click!

# 1. Copy dlls from solutionDir (i.e. $projectDir\..\)
Write-Host "Copying dlls to output dir..."
Copy-Item -Path "$projectDir\..\OpenGL.SharedModule\dependencies\dlls\*" -Destination "$outputPath" -Force -Recurse

# 2. Copy shaders
Write-Host "Copying shaders to output dir..."
Copy-Item -Path "$projectDir\shaders" -Destination "$outputPath" -Force -Recurse

# 3. Copy resources
Write-Host "Copying resources to output dir..."
Copy-Item -Path "$projectDir\resources" -Destination "$outputPath" -Force -Recurse

# Now, let's package the output as a deliverable (installer.exe)

# TODO with NSIS

Write-Host "DONE."