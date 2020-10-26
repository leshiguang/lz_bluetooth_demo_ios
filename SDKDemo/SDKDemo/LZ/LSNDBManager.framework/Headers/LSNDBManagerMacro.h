//
//  LSNDBManagerMacro.h
//  LSNDBManager
//
//  Created by Wenzheng Zhang on 2017/10/4.
//  Copyright © 2017年 Wenzheng Zhang. All rights reserved.
//

#ifndef LSNDBManagerMacro_h
#define LSNDBManagerMacro_h

#import <WCDB/WCDB.h>

#define LSNDB_IMPLEMENTATION(className) WCDB_IMPLEMENTATION(className)

//Property - declare column
#define LSNDB_PROPERTY(propertyName) WCDB_PROPERTY(propertyName)

//Synthesize - implement column
#define LSNDB_SYNTHESIZE(className, propertyName) \
        WCDB_SYNTHESIZE(className, propertyName)

#define LSNDB_SYNTHESIZE_COLUMN(className, propertyName, columnName) \
        WCDB_SYNTHESIZE_COLUMN(className, propertyName, columnName)

#define LSNDB_SYNTHESIZE_DEFAULT(className, propertyName, defaultValue) \
        WCDB_SYNTHESIZE_DEFAULT(className, propertyName, defaultValue)

#define LSNDB_SYNTHESIZE_COLUMN_DEFAULT(className, propertyName, columnName, defaultValue) \
        WCDB_SYNTHESIZE_COLUMN_DEFAULT(className, propertyName, columnName, defaultValue)

//Constraint
//Column Constraint
#define LSNDB_PRIMARY(className, propertyName)                                  \
        WCDB_PRIMARY(className, propertyName)

#define LSNDB_PRIMARY_ASC(className, propertyName)                              \
        WCDB_PRIMARY_ASC(className, propertyName)

#define LSNDB_PRIMARY_DESC(className, propertyName)                             \
        WCDB_PRIMARY_DESC(className, propertyName)

#define LSNDB_PRIMARY_AUTO_INCREMENT(className, propertyName)                   \
        WCDB_PRIMARY_AUTO_INCREMENT(className, propertyName)

#define LSNDB_PRIMARY_ASC_AUTO_INCREMENT(className, propertyName)               \
        WCDB_PRIMARY_ASC_AUTO_INCREMENT(className, propertyName)

#define LSNDB_PRIMARY_IMP(className, propertyName, order, isAutoIncrement,      \
onConflict)                                           \
        WCDB_PRIMARY_IMP(className, propertyName, order, isAutoIncrement,      \
onConflict)

#define LSNDB_NOT_NULL(className, propertyName)                                 \
        WCDB_NOT_NULL(className, propertyName)

#define LSNDB_UNIQUE(className, propertyName)                                   \
        WCDB_UNIQUE(className, propertyName)

//Table Constraint
#define LSNDB_MULTI_PRIMARY(className, constraintName, propertyName)            \
        WCDB_MULTI_PRIMARY(className, constraintName, propertyName)

#define LSNDB_MULTI_PRIMARY_ASC(className, constraintName, propertyName)        \
        WCDB_MULTI_PRIMARY_ASC(className, constraintName, propertyName)

#define LSNDB_MULTI_PRIMARY_DESC(className, constraintName, propertyName)       \
        WCDB_MULTI_PRIMARY_DESC(className, constraintName, propertyName)

#define LSNDB_MULTI_PRIMARY_CONFLICT(className, constraintName, onConflict)     \
        WCDB_MULTI_PRIMARY_CONFLICT(className, constraintName, onConflict)

#define LSNDB_MULTI_UNIQUE(className, constraintName, propertyName)             \
        WCDB_MULTI_UNIQUE(className, constraintName, propertyName)

#define LSNDB_MULTI_UNIQUE_ASC(className, constraintName, propertyName)         \
        WCDB_MULTI_UNIQUE_ASC(className, constraintName, propertyName)

#define LSNDB_MULTI_UNIQUE_DESC(className, constraintName, propertyName)        \
        WCDB_MULTI_UNIQUE_DESC(className, constraintName, propertyName)

#define LSNDB_MULTI_UNIQUE_CONFLICT(className, constraintName, onConflict)      \
        WCDB_MULTI_UNIQUE_CONFLICT(className, constraintName, onConflict)

#define LSNDB_CHECK(className, constraintName, check)                           \
        WCDB_CHECK(className, constraintName, check)

//Index
#define LSNDB_INDEX(className, indexSubfixName, propertyName)                   \
        WCDB_INDEX(className, indexSubfixName, propertyName)

#define LSNDB_INDEX_ASC(className, indexSubfixName, propertyName)               \
        WCDB_INDEX_ASC(className, indexSubfixName, propertyName)

#define LSNDB_INDEX_DESC(className, indexSubfixName, propertyName)              \
        WCDB_INDEX_DESC(className, indexSubfixName, propertyName)

#define LSNDB_UNIQUE_INDEX(className, indexSubfixName, propertyName)            \
        WCDB_UNIQUE_INDEX(className, indexSubfixName, propertyName)

#define LSNDB_UNIQUE_INDEX_ASC(className, indexSubfixName, propertyName)        \
        WCDB_UNIQUE_INDEX_ASC(className, indexSubfixName, propertyName)

#define LSNDB_UNIQUE_INDEX_DESC(className, indexSubfixName, propertyName)       \
        WCDB_UNIQUE_INDEX_DESC(className, indexSubfixName, propertyName)

//Virtual Table Argument
#define LSNDB_VIRTUAL_TABLE_ARGUMENT(className, left, right)                    \
        WCDB_VIRTUAL_TABLE_ARGUMENT(className, left, right)

#define LSNDB_VIRTUAL_TABLE_TOKENIZE(className, tokenizeName)                   \
        WCDB_VIRTUAL_TABLE_TOKENIZE(className, tokenizeName)

#define LSNDB_VIRTUAL_TABLE_MODULE(className, moduleName)                       \
        WCDB_VIRTUAL_TABLE_MODULE(className, moduleName)

#endif /* LSNDBManagerMacro_h */
