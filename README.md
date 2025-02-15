سون سگمنت:
این آرایه به صورت دو بعدی طراحی شده و هر عنصر در این آرایه یکی از اعداد ۰ تا ۹ را نمایندگی می‌کند.
هر عدد توسط یک آرایه ۷ تایی از مقادیر ۰ و ۱ تعریف می‌شود که ۷ سگمنت نمایشگر ۷-سگمنتی را کنترل می‌کند.
هر مقدار ۱ نشان‌دهنده روشن بودن و مقدار ۰ نشان‌دهنده خاموش بودن آن سگمنت است.
این تابع مقادیر آرایه sequence را برای یک عدد خاص (۰ تا ۹) می‌خواند.
برای هر سگمنت، این تابع از digitalWrite برای اعمال وضعیت (روشن یا خاموش) به سگمنت‌های متصل به پین‌های ۱ تا ۷ استفاده می‌کند.
۳. تابع setup
پین‌های ۱ تا ۷ آردوینو به عنوان خروجی تنظیم می‌شوند
زیرا هر کدام با یک سگمنت از نمایشگر متصل هستند.
این تنظیمات اجازه می‌دهد که بتوانید به‌صورت دیجیتالی این پین‌ها را کنترل کنید.
۴. تابع loop
این حلقه به صورت پیوسته اجرا می‌شود و عدد ۰ تا ۹ را نمایش می‌دهد.
با استفاده از تابع printNumber، هر عدد به مدت یک ثانیه روی نمایشگر نشان داده می‌شود (به‌وسیله‌ی delay(1000)).
 به طور مستمر اعداد ۰ تا ۹ را روی یک نمایشگر ۷-سگمنتی نمایش می‌دهد، با این فرض که سگمنت‌ها به ترتیب به پین‌های ۱ تا ۷ آردوینو متصل شده‌اند. هر یک از این پین‌ها روشن/خاموش بودن یک سگمنت خاص را کنترل می‌کند.
 فتوسل:  
تعریف متغیرها
int sensor;
int led=13;
int sensor;: این متغیر برای ذخیره مقدار خوانده شده از یک سنسور آنالوگ استفاده می‌شود.
int led=13;: این متغیر پین شماره 13 را برای یک LED تعریف می‌کند. در اکثر بوردهای Arduino، پین 13 دارای یک LED داخلی است که می‌تواند برای نمایش وضعیت روشن یا خاموش بودن استفاده شود
Serial.begin(9600);: این خط ارتباط سریالی را با سرعت 9600 بیت بر ثانیه تنظیم می‌کند. این به شما امکان می‌دهد داده‌ها را از میکروکنترلر به کامپیوتر بفرستید، که در اینجا برای نمایش مقدار سنسور استفاده می‌شود.
pinMode(led, OUTPUT);: این خط پین 13 (LED) را به عنوان خروجی تنظیم می‌کن
sensor = analogRead(A0);: این خط مقدار آنالوگ خوانده شده از پین A0 (که فرض می‌شود به یک سنسور متصل شده است) را به متغیر sensor نسبت می‌دهد.
Serial.print("sensor value=");: این خط یک رشته متنی را در Serial Monitor چاپ می‌کند.
Serial.println(sensor);: این خط مقدار سنسور را در Serial Monitor چاپ می‌کند و سپس به خط بعدی می‌رود.
delay(300);: این خط باعث می‌شود که برنامه به مدت 300 میلی‌ثانیه منتظر بماند قبل از اینکه بخش بعدی کد اجرا شود.
if(sensor > 120){ digitalWrite(led, LOW); }: اگر مقدار خوانده شده از سنسور بیشتر از 120 باشد، LED خاموش می‌شود (LOW).
else{ digitalWrite(led, HIGH); }: در غیر این صورت، LED روشن می‌شود (HIGH).
نتیجه‌گیری
این کد به طور کلی یک برنامه ساده است که مقدار خوانده شده از یک سنسور آنالوگ (متصل به پین A0) را می‌خواند و در Serial Monitor چاپ می‌کند. همچنین، اگر مقدار سنسور بالای 120 باشد، LED خاموش می‌شود و در غیر این صورت روشن می‌ماند.

پیانو:
تعریف متغیرها
#define T_C 262
#define T_D 294
#define T_E 330
#define T_F 349
#define T_G 392
#define T_A 440
#define T_B 49
در اینجا، نت‌های موسیقی با فرکانس‌های معین تعریف شده‌اند. به عنوان مثال:

T_C برابر با 262 هرتز (نت دو)
T_D برابر با 294 هرتز (نت ر)
و به همین ترتیب برای دیگر نت‌ها.
تعریف پین‌ها
const int A = 5;
const int B = 6;
const int C = 7;
const int D = 8;
const int Burr = 11
A, B, C, D: برای ورودی‌های دیجیتال
Burr: برای تولید صدا که به پین 11 متصل شده است.
تابع setup
چهار پین (A, B, C, D) به عنوان ورودی تعریف شده‌اند و با مقدار HIGH فعال شده‌اند. این کار برای جلوگیری از قطع و وصل‌های ناخواسته است‌.
در این قسمت، در یک حلقه بی‌پایان (loop) بررسی می‌شود که آیا یکی از پین‌ها (A, B, C, یا D) به LOW تغییر وضعیت داده است یا خیر:

اگر پین A LOW باشد، نت C (262 هرتز) پخش می‌شود.
اگر پین B LOW باشد، نت D (294 هرتز) پخش می‌شود.
اگر پین C LOW باشد، نت E (330 هرتز) پخش می‌شود.
اگر پین D LOW باشد، نت F (349 هرتز) پخش می‌شود.
سپس، اگر هیچ یک از پین‌ها LOW نباشند (noTone(Burr))، هیچ صدایی تولید نمی‌شود.
بلندگو:
کتابخانه pitches.h: این فایل شامل تعاریف نت‌های موسیقی است. بنابراین با استفاده از این کتابخانه، می‌توانیم به نام نت‌ها مانند NOTE_C4 و NOTE_G3 اشاره کنیم.
و NOTE_G3 اشاره کنیم.
آرایه melody: این آرایه حاوی نت‌های موزیک است که قرار است به ترتیب پخش شوند. به عنوان مثال:

NOTE_C4: نت دو در اکتاو چهارم
NOTE_G3: نت سل در اکتاو سوم
آرایه noteDurations: این آرایه حاوی مدت زمان هر نت به صورت وضعیت‌های زمانی (کوارتر، ایت، و غیره) است.
مقدار 4 به معنای نت کوارت و 8 به معنای نت ایت است.
تابع setup()
در این تابع، حلقه‌ای به کمک for برای تکرار نت‌های موزیک تعریف شده است.
برای هر نت:
مدت زمان نت با فرمول 1000/noteDurations[thisNote] محاسبه می‌شود. این فرمول به ما این امکان را می‌دهد که مدت زمان هر نت را به میلی‌ثانیه محاسبه کنیم.
تابع tone() برای تولید صدا روی پایه ۸ (حالت پیش‌فرض) با فرکانس هر نت و مدت زمان محاسبه شده صدا را پخش می‌کند.
سپس با استفاده از delay(noteDuration + 30) برنامه به مدت زمان نت به علاوه ۳۰ میلی‌ثانیه استراحت می‌کند، که به اجزای صوتی اجازه می‌دهد تا به درستی شنیده شوند.
تابع loop():
این تابع به طور خالی باقی مانده است زیرا نیازی به تکرار موزیک وجود ندارد. پس از پخش اولین بار، برنامه متوقف می‌شود.
این کد برای پخش یک ملودی ساده طراحی شده است.
سنسوردما
تعریف متغیرها:
int sensor; int led=13; content_copy 
sensor: یک متغیر برای ذخیره‌ی مقدار خوانده شده از حسگر.
led: شماره‌ی پین LED که به آنالوگ پین 13 متصل شده 
Serial.begin(9600): این خط برای راه‌اندازی ارتباط سریال با سرعت 9600 بیت در ثانیه استفاده می‌شود. به این خاطرکه می‌توانیم داده‌ها را به کامپیوتر ارسال کنیم.
pinMode(led,OUTPUT): با این دستور مشخص می‌کنیم که پین 13 (LED) به عنوان خروجی استفاده خواهد شد.


sensor=analogRead(A0): این خط مقدار آنالوگ خوانده شده از پایه A0 (که فرضاً به یک حسگر متصل است) را ذخیره می‌کند.
Serial.print() و Serial.println(): این دو دستور مقدار حسگر را در کنسول سریال چاپ می‌کند.
delay(300): برنامه به مدت 300 میلی‌ثانیه متوقف می‌شود.

کنترل LED بر اساس مقدار حسگر
این قسمت بررسی می‌کند که آیا مقدار حسگر بیشتر از 120 است یا نه
اگر مقدار بیشتر از 120 باشد، LED خاموش می‌شود (چراکه LOW به معنای خاموشی LED است).
اگر مقدار کمتر یا مساوی 120 باشد، LED روشن می‌شود (با HIGH)
این کد در واقع یک سیستم اندازه‌گیری ساده است که به کاربر اجازه می‌دهد وضعیت یک LED را بر اساس مقدار خوانده شده از یک حسگر آنالوگ کنترل کند. اگر مقدار حسگر از یک آستانه مشخص (120) بیشتر شود، LED خاموش می‌گردد، در غیر این صورت LED روشن می‌ماند.
