# UPDATE salary
SET sex =
    CASE sex
        WHEN 'f' THEN 'm'
        ELSE 'f'
    END;

-- Another solution (faster one)
UPDATE salary
SET sex = IF(sex = 'm', 'f', 'm');
       
