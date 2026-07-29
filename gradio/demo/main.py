import gradio as gr

def greet(name:str,intensity:float)->str:
    r"""
    功能函数
    """
    return "Hello, "+name+"!"*int(intensity)

# 界面配置
app=gr.Interface(
        fn=greet,
        inputs=["text","slider"],
        outputs=["text"],
        api_name="predict"
    )

if __name__ == '__main__':
    app.launch()
