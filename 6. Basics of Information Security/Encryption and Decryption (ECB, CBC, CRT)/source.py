from IPython.display import Image
path = './test1.png'
# path = './Pic_project_input.png'
Image(filename= path)



from PIL import Image
from Crypto.Cipher import AES

filename = path
filename_out = 'out_encrypted'
format = 'png'
key = 'aaaabbbbccccdddd' #'0000111122223333'

# AES requires that plaintexts be a multiple of 16, so we have to pad the data
def pad(data):
    return data + b"\x00"*(16-len(data)%16)

# Maps the RGB
def convert_to_RGB(data):
    r, g, b = tuple(map(lambda d: [data[i] for i in range(0,len(data)) if i % 3 == d], [0, 1, 2]))
    pixels = tuple(zip(r,g,b))
    return pixels
    
def process_image(filename):
    # Opens image and converts it to RGB format for PIL
    im = Image.open(filename)
    data = im.convert("RGB").tobytes()

    # Since we will pad the data to satisfy AES's multiple-of-16 requirement, we will store the original data length and "unpad" it later.
    original = len(data)

    # Encrypts using desired AES mode (we'll set it to ECB by default)
    new = convert_to_RGB(aes_ecb_encrypt(key, pad(data))[:original])
    
    # Create a new PIL Image object and save the old image data into the new image.
    im2 = Image.new(im.mode, im.size)
    im2.putdata(new)
    
    #Save image
    im2.save(filename_out + '.' + format, format)

# ECB 
def aes_ecb_encrypt(key, data, mode=AES.MODE_ECB):
    aes = AES.new(key, mode)
    new_data = aes.encrypt(data)
    return new_data
# CBC 
def aes_cbc_encrypt(key, data, mode=AES.MODE_CBC):
    IV = "A"*16  #We'll manually set the initialization vector to simplify things
    aes = AES.new(key, mode, IV)
    new_data = aes.encrypt(data)
    return new_data
# CRT
def aes_crt_encrypt(key, data, mode=AES.MODE_CTR):
    aes = AES.new(key, mode, counter = Crypto.Util.Counter.new(128, initial_value = 1, allow_wraparound = True))
    new_data = aes.encrypt(data)
    return new_data
 
process_image(filename)



from IPython.display import Image
Image(filename= filename_out+'.'+format)