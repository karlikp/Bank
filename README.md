# 🏦 Bank 	
### 💬 Context of the project:
This was my main project from the second semester of my studies.
I developed it as part of a computer programming course.

### 🚀 My motivation:
I decided to take on this project to work on real-life issues. 
Banks play a crucial role in today's world. 
Automating the loan approval process would benefit consultants by saving their time and their employers' money.

## 🛠️ How the program works
This program provides loans to individuals or companies.
  Both individual customers and companies can benefit from three types of loans.

Loan for individual clients:
- Mortgage credit (APR - Annual Percentage Rate: 10%)
The credit you can receive providing that you use it only to buy real property.
- Consolidation credit (APR: 15%)
The credit you can receive providing that you will use it to repay other credit.
- Consumer credit (APR: 20%)
The credit you can receive provided you aren't using them for your business.


Loan for companies:
- Investment credit (APR: 6%)
The credit you can receive provided you use them to develop your business.
- Working capital credit (APR: 8%)
The credit you can receive provided you use them for settling your current expenses in company.
- Start-up credit (APR: 10%)
The credit you can receive provided you use them to start your business.

For each type of loan, the program goes through a similar path, modified appropriate to the specific of each loan.
The general sketch of the project is illustrated in a block diagram on the miro platform:
https://miro.com/app/board/uXjVMHVvLIQ=/?share_link_id=838234918176

<br>****Point summary****
1. The customer selects the type of loan,
2. The customer accepts the terms,
3. The customer loads his personal data from the file,
4. Alternatively, enter data from the keyboard,
5. The customer enters and decides on the loan amount and its repayment period,
6. The program calculates creditworthiness, later called "credit capacity", based on the information provided,
7. The program checks whether the client has sufficient credit capacity to receive a loan,
8. The program informs about the success or failure of the loan
9. If the loan has been granted, the information is saved to a text file in the `/Bank/Source/Customers` directory,
10. The customer chooses whether he wants to get another loan or exit the program.

## 📌 To run the program:
1. Clone the repository
2. Change your working directory to the `Source` by cd `Bank/Source`
3. Compile with g++:
- On Linux `g++ *.cpp -I /Headers -o bank`
- On Windows by `g++ *.cpp -I \Headers -o bank`
4. Run the executable:
- On Linux by `./bank`
- On Windows by `bank`
5. You can complete personal data using the keyboard or attach a text file. <br>
If you want to upload data from a text file, you must place the file with the appropriate data in the `Bank/Source` folder
6. When starting the program, you will be asked to enter the name of the data file.<br> Then you should enter the file name with the extension, e.g. testCustomer1.txt
7. If the loan is successful, customer and loan data will be saved to a text file in the directory at `Bank/Source/Customers`

### 📷 Galery:

![Pledge_true](https://github.com/karlikp/Bank/assets/115083597/12152da6-9204-4275-8a58-55f6b4489e90)
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  pict.1 Pattern of DataCustomer.txt with plegde</p><br>

![Pledge_false](https://github.com/karlikp/Bank/assets/115083597/fd004222-0c5d-4996-835a-4c14c899f84e)
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  pict.2 Pattern of DataCustomer.txt without plegde</p><br>
  
![Output](https://github.com/karlikp/Bank/assets/115083597/a2ae03cc-afc3-4154-b2c7-329b48c2edbf)
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  pict.3 Output file containing customer and credit data</p><br>






