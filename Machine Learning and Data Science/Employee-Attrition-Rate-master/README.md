# Predicting-Employee-Attrition-Rate
![picture alt](https://github.com/feyre-2001/Employee-Attrition-Rate/blob/master/p2.png)
As the COVID-19 keeps unleashing its havoc, the world continues to get pushed into the crisis of the great economic recession, more and more companies start to cut down their underperforming employees. Companies firing hundreds and thousands of Employees is a typical headline today. Cutting down employees or reducing an employee salary is a tough decision to take. It needs to be taken with utmost care as imprecision in the identification of employees whose performance is attriting may lead to sabotaging of both employees' career and the company's reputation in the market.

## Aim
To predict Employee Attrition by the given data about his/her past history.

## Evaluation
The evaluation metric for this competition is AUC score under ROC. AUC - ROC curve is a performance measurement for classification problem at various thresholds settings. ROC is a probability curve and AUC represents degree or measure of separability. It tells how much model is capable of distinguishing between classes. Higher the AUC, better the model is at predicting 0s as 0s and 1s as 1s. By analogy, Higher the AUC, better the model is at distinguishing between patients with disease and no disease.

## Brief Overview of the Approach
- After loading the datasets, I observed all the features of the dataset using EDA and libraries like matplotlib and seaborn. This helped me in seeing the various trends and impacts of how various features affected the attrition rate.
- After this I encoded the various numerical and categorical features of the dataset through LabelEncoding and OneHotEncoding.
- Feature Scaling was the next step for preprocessing my dataset. Since the raw data varies widely, it is better to normalize it through scaling like StandardScaler or MinMaxScaler.
- After applying GridSearch, we chose the best model to be Logistic Regression and fitted the dataset.
- Feature Selection furhter helped to increase the AUC-ROC score.

## Evaluation
The model acheived a score of 0.852.
