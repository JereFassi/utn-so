import sys
import subprocess
from pathlib import Path

def open_paint_with_image(image_path):
  # Default image path
  default_image = Path(r"C:\\Users\\Usuario\\Proyectos\\utn-so\\recursos\\img\\Evolv.jpg")
    
  # Check if using default image
  if image_path.lower() == "default":
      image_path = str(default_image)
    
  # Paint executable path
  paint_path = r"C:\\Program Files\\WindowsApps\\Microsoft.Paint_11.2502.161.0_x64__8wekyb3d8bbwe\\PaintApp\\mspaint.exe"
  
  print(f"Image Path: {image_path}")
  print(f"Default Image Path: {default_image}")

  try:
    # Create and wait for the process
    process = subprocess.Popen([paint_path, image_path])
    print("Paint process started...")
    process.wait()
    print("Paint process completed")
  except subprocess.CalledProcessError as e:
    print(f"Error creating process: {e}")
    return 1
  except FileNotFoundError:
    print("Error: Paint executable not found")
    return 1

def main():
  if len(sys.argv) != 2:
    print(f"Usage: {sys.argv[0]} <path-to-image>")
    print(f"Example: {sys.argv[0]} C:\\Users\\Pictures\\image.jpg")
    print(f"Or use 'default' to open the default image")
    return 1

  return open_paint_with_image(sys.argv[1])

if __name__ == "__main__":
  sys.exit(main())