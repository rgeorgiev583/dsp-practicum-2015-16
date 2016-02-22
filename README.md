# dsp-practicum-2015-16
Програмите от практикума по СДП на специалност КН
във ФМИ-СУ, 2. курс, 2. поток, 2015/16 г.

## Крайни резултати

<table border="1">
<tr>
<th>ФН</th>
<th>Контролно</th>
<th>Домашно 1</th>
<th>Домашно 2</th>
<th>Контролно (точки)</th>
<th>Домашно 1 (точки)</th>
<th>Домашно 2 (точки)</th>
<th>Точки (без проект)</th>
</tr>
<tr>
<td>81096</td>
<td>5.90</td>
<td>6.00</td>
<td>6.00</td>
<td>49</td>
<td>10</td>
<td>10</td>
<td>69</td>
</tr>
<tr>
<td>81136</td>
<td>3.70</td>
<td>3.50</td>
<td>-</td>
<td>21</td>
<td>4</td>
<td>-</td>
<td>25</td>
</tr>
<tr>
<td>81203</td>
<td>4.80</td>
<td>6.00</td>
<td>-</td>
<td>35</td>
<td>10</td>
<td>-</td>
<td>45</td>
</tr>
<tr>
<td>81179</td>
<td>5.20</td>
<td>6.00</td>
<td>6.00</td>
<td>40</td>
<td>10</td>
<td>10</td>
<td>60</td>
</tr>
<tr>
<td>81153</td>
<td>5.50</td>
<td>6.00</td>
<td>-</td>
<td>44</td>
<td>10</td>
<td>-</td>
<td>54</td>
</tr>
<tr>
<td>81161</td>
<td>5.80</td>
<td>6.00</td>
<td>6.00</td>
<td>48</td>
<td>10</td>
<td>10</td>
<td>68</td>
</tr>
<tr>
<td>81170</td>
<td>5.90</td>
<td>6.00</td>
<td>6.00</td>
<td>49</td>
<td>10</td>
<td>10</td>
<td>69</td>
</tr>
<tr>
<td>81227</td>
<td>5.50</td>
<td>6.00</td>
<td>6.00</td>
<td>44</td>
<td>10</td>
<td>10</td>
<td>64</td>
</tr>
<tr>
<td>81112</td>
<td>5.90</td>
<td>6.00</td>
<td>6.00</td>
<td>49</td>
<td>10</td>
<td>10</td>
<td>69</td>
</tr>
<tr>
<td>81195</td>
<td>5.50</td>
<td>6.00</td>
<td>6.00</t>
<td>44</td>
<td>10</td>
<td>10</td>
<td>64</td>
</tr>
<tr>
<td>81112</td>
<td>5.90</td>
<td>6.00</td>
<td>6.00</td>
<td>49</td>
<td>10</td>
<td>10</td>
<td>69</td>
</tr>
<tr>
<td>81195</td>
<td>5.50</td>
<td>6.00</td>
<td>6.00</td>
<td>44</td>
<td>10</td>
<td>10</td>
<td>64</td>
</tr>
<tr>
<td>81104</td>
<td>5.30</td>
<td>5.70</td>
<td>6.00</td>
<td>41</td>
<td>9</td>
<td>10</td>
<td>60</td>
</tr>
<tr>
<td>81187</td>
<td>5.70</td>
<td>5.50</td>
<td>6.00</td>
<td>46</td>
<td>9</td>
<td>10</td>
<td>65</td>
</tr>
<tr>
<td>81120</td>
<td>4.50</td>
<td>6.00</td>
<td>6.00</td>
<td>31</td>
<td>10</td>
<td>10</td>
<td>51</td>
</tr>
</table>

## Какво (*ще*) съдържа това хранилище (repo)?
Tук ще се добавят условия на задачи и примерни решения на задачите.
Ще бъдат качвани и решения, ако изпратите **pull request**, но, разбира се,
след като бъдат коригирани евентуално съществуващи бъгове и други проблеми по
тях.

Ако желаете да изпратите решение за дадено задание, процедурата е следната:

1. Fork-вате repo-то.
2. Създавате папка с името на даденото задание.
3. Вътре добавяте source файловете.
4. Правите pull request, чието заглавие започва с факултетния ви номер.

Така ще мога автоматично да merge-вам решенията.

## Малко команди, които ще са ви полезни в това начинание...
*NB*: Би трябвало да работят във всеки shell под Unix-базирани ОС
(т.е. **bash/zsh/csh/fish** etc. под **Linux/BSD/OS X** и т.н.), както и в
**Git shell/Cygwin/MSYS** под Windows.

### Първо, преди да направите каквото и да е друго,

fork-нете официалното (*mainstream*/*parent*) repo-то в GitHub, за да можете
да предлагате неща за добавяне там (т.нар. **pull requests**).
Това ще е необходимо, тъй като няма да имате правомощия за push-ване (вж. долу) към него.)

Няма да го обяснявам тук как става, тъй като в
[help сайта на GitHub вече е обяснено много добре](https://help.github.com/articles/fork-a-repo/).

### За да си клонирате (създадете *локална версия*) на repo-то (fork-натото!)

    $ git clone *url*

и текущата директория магически ще се превърне в хранилище.
(*NB*: Заместете *url* с адреса на fork-натото repo, т.е. вашата версия на
repo-то в GitHub.)

### За да си добавите току-що създаден файл (например решена задача) в repo-то,

*т.е. да го "commit"-нете*:

    $ git add *filename*
    $ git commit -m '*описание какво точно сте добавили (какво прави, etc.)*'
    $ git push -u origin master

(*NB*: Последната стъпка всъщност не е задължителна.  Тя просто добавя промените
(commit-ите), направени в локалното repo (т.е. клонираното от вас), към
отдалеченото (т.е. това в GitHub.)
Получава се нещо като "синхронизация" на repo-тата.

### За да създадете pull request

Първо добавете официалното repo на курса като нов remote и създайте нов branch за него
(на базата на който ще правите pull request-а:

    $ git remote add mainstream *mainstream-url*
    $ git checkout -b changes mainstream/master

(Можете да погледнете [този](http://stackoverflow.com/questions/5256021/send-a-pull-request-on-github-for-only-latest-commit) thread в StackOverflow за повече информация.)

По-нататъшните стъпки са обяснени [по подобаващ начин в help сайта на GitHub](https://help.github.com/articles/using-pull-requests/).

## За повече информация

### За Git и GitHub:

* [Официалният сайт на Git](https://git-scm.com/)
* [Помощ за GitHub](https://help.github.com/)

### За C++:

* [C++ reference #1](http://www.cplusplus.com/)
* [C++ reference #2](http://en.cppreference.com/)
