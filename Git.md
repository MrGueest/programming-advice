# ابدأ مع git
###### بقلم دحمان
##التحميل
[تحميل من الموقع الرسمي](https://git-scm.com/download/win "تحميل من الموقع الرسمي")
يمكنك المتابعة بنفسك اذا لم تستطع git  لم يصنع لك 
## التسجيل في github من خلال git
قم بتشغيل cmd وتحقق انك  في المجلد `c:/Users/YOU`   
` YOU` يمثل اسمك  لذا سيختلف من كمبيوتر الى اخر ولكن ان تكن في ذلك المجلد ف انتقل اليه من خلال  
```bash
cd %USERPROFILE%
```
بعد ذلك اكتب الأوامر التالية
```bash
git config --global user.name "John Doe"
```
بالطبع غيرJohn Doe بأسمك الحقيقي المسجل في github
```bash
git config --global user.email johndoe@example.com
```
غير johndoe@example.com ب ايميلك الذي سجلت به في **github**
لهذه المرحلة لم ندخل اي كلمة سر  كما نرى
##تأكيد حسابك 
في هذا الشرح سوف نستخدم **ssh**
###معلومة صغيرة حول  ssh
الssh يحتوي على مفتاحين احدهما عام نرسله الى github والاخر خاص يحفظ في الجهاز في الخطوة التالية سوف نقوم بانشاء مفتاح  ssh  وارساله الى github
###انشاء المفتاح(الخاص و العام)
انشء مجدد باسم  `.ssh` وتنقل اليه من خلال
```bash
mkdir .ssh
cd .ssh
```
من ثم اكتب الامر التالي
```bash
ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
```
قم باستبدال  `your_email@example.com` بأيميلك 
ستظهر لك هذه رسالة
`> Generating public/private ALGORITHM key pair.`
هنيهة صغيرة ثم تظهر هذه الرسالة
`> Enter file in which to save the key (/c/Users/YOU/.ssh/id_ALGORITHM):[Press enter]`
اضغط `enter` اذا ظهر لك اي اسم اخر في مكان `id_rsa`  لا تظغط `enter`  بل اكتب `id_rsa` ومن  ثم  اظغط `enter`  
####حجز مفتاحك العام داخل Github 
ماعليك الا بكتابة
```bash
type %userprofile%\.ssh\id_rsa.pub | clip
```
لقد قمت بنسخ المفتاح بنجاح معليك الان الا  وضعه داخل **Github**  وذلك بالانتقال الى  الصفحة التالية  **[هنا](http://https://github.com/settings/keys "
هنا")** ستظهر مربع كتابة عنوان يمكنك كتابة اي اسم للمفتاح لكي تتذكره  وفي مربع الثاني ضع المفتاح لا تقلق لقد نسخته باستخدام الامر الاخير ومن ثم قم بحفظ  قد يطالبك بادخال كلمة السر للاكمال
####تحقق من المفتاح 
```ssh -T git@github.com```
### لمسات اخيرة
سوف نقوم ب استنساخ`programing-advice` repostory والتعديل عليه ثم رفعه للتحقق من ان كل شيئ جاهز
ننتقل الى سطح المكتب 
```bash
cd %userprofile%\desktop 
REM للانتقال الى سطح المكتب
mkdir "github workspace"
REM لانشاء مجلد باسم github workspace ليكون كمجل خاص ب github
git clone https://github.com/MrGueest/programming-advice 
REM لاستنساخ مجلد الخاص ب programming-advice لنسخة محلية 
cd programming-advice 
REM للدخول اليه
echo hi i am %USERNAME% and i have successfuly flowed the tutorial>>README.md
REM تعديل بسيط على الملف README.md
git add README.md
git commit -m "simple edit"
git push
REM لرفع التحديث الى github
```
