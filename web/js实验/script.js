var x=prompt('请输入：');
alert('你说啥？');
var info = '哦，你说了'+x+'啊';
alert(info);
console.log('又有个傻逼点开了这玩意');
/* 变量声明距离：var x; 声明一个名称为x的变量
var x;
x=1; 赋值x为1
或，类似C语言
var x=1;
命名时规避‘name’
*/
//三种数字转字符串方式
var num=1;alert(num.toString());//String的S必须大写
var num=1;alert(String(num));
var num=1;alert(num+"");