/* Write your PL/SQL query statement below */
Select p.firstname, p.lastName , a.city , a.state 
from Person p
left join Address a
on p.personId=a.personId;