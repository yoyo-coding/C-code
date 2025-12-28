from PIL import Image
# 输入数据
hex_data = [
    "00FFCFAB00FFAC09071B5CCFAB76",
    "00AFCBAB11FFAB09981D34CFAF56",
    "01BFCEAB00FFAC0907F25FCFBA65",
    "10FBCBAB11FFAB09981DF4CFCA67",
    "00FFCBFB00FFAC0907A25CCFFC76",
    "00FFCBAB1CFFCB09FC1AC4CFCF67",
    "01FCCBAB00FFAC0F071A54CFBA65",
    "10EFCBAB11FFAB09981B34CFCF67",
    "01FFCBAB00FFAC0F071054CFAC76",
    "1000CBAB11FFAB0A981B84CFCF66"
]

# 颜色转换函数
def hex_to_rgb(hex_str):
    if hex_str == "FF":
        return (0, 0, 0)       # 黑色
    elif hex_str == "00":
        return (255, 255, 255) # 白色
    else:
        gray_value = int(hex_str, 16)
        return (gray_value, gray_value, gray_value)  # 灰度

# 构建像素列表
width = 13  # 每行 26 个字符 / 2 = 13 像素
height = len(hex_data)

pixels = []
for line in hex_data:
    row_pixels = []
    for i in range(0, len(line), 2):
        hex_pair = line[i:i+2]
        row_pixels.append(hex_to_rgb(hex_pair))
    pixels.append(row_pixels)

# 创建图像
image = Image.new("RGB", (width, height))
for y in range(height):
    for x in range(width):
        image.putpixel((x, y), pixels[y][x])

# 保存并显示图像
image.save("output_grayscale.png")
image.show()

print("图像已保存为 output_grayscale.png")