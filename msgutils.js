var context;
// 初始化
function init()
{
    if (typeof qt != 'undefined')
    {
        new QWebChannel(qt.webChannelTransport, function(channel)
        {
        context = channel.objects.context;
        }
        );
    }
    else
    {
        alert("qt对象获取失败！");
    }
}
// 向qt发送消息
function sendMessage(x,y)
{
    if(typeof context == 'undefined')
    {
        alert("context对象获取失败！");
    }
    else
    {
        context.getpixel(x,y);
    }
}
init();
