SELECT W1.id
FROM Weather W1
JOIN Weather W2
  ON W1.recordDate = W2.recordDate + 1
WHERE W1.temperature > W2.temperature;
