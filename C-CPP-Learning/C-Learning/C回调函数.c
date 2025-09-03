// 在我们平时开发STM32或者其它单片机时，我们经常都会用到原厂提供的固件库函数，固件库函数中有非常多回调函数。

// 那么什么是回调函数呢？
// 回调函数是作为参数传递给另一个函数的函数
// 接受回调作为参数的函数预计会在某个时间点执行它
// 回调机制允许下层软件层调用上层软件层定义的函数

// 用户应用程序代码和硬件驱动程序之间的交互:
// 硬件驱动程序是一个独立的可重用驱动程序，它不了解上面的层(在本例中为用户应用程序)
// 硬件驱动程序提供 API 函数，允许用户应用程序将函数注册为回调。

// 然后，**此回调函数由硬件驱动程序作为执行的一部分进行调用。**
// 如果不使用回调，就会被编码为直接调用。这将使硬件驱动程序特定于特定的高级软件级别，并降低其可重用性。
// 回调机制的另一个好处是，在程序执行期间可以动态更改被调用的回调函数。

// 1、C语言中的回调

// 不同的编程语言有不同的实现回调的方式。在本文中，我们将重点介绍C编程语言，因为它是用于嵌入式软件开发的最流行的语言。
// **C语言中的回调是使用函数指针实现的。**函数指针就像普通指针一样，但它不是指向变量的地址，而是指向函数的地址。

// 在程序运行期间，可以设置相同的函数指针指向不同的函数。
// 在下面的代码中，我们可以看到如何==使用函数指针将函数作为参数传递给函数。
// ==该函数将函数指针和两个整数值作为参数和。将执行的算术运算取决于将传递给函数指针参数的函数。

// uint16_t cal_sum(uint8_t a, uint8_t b) 
// {
//     return a + b;
// }
// uint16_t cal_mul(uint8_t a, uint8_t b) 
// {
//     return a * b;
// }
// uint16_t cal_op (uint16_t (*callback_func)(uint8_t, uint8_t),uint8_t a, uint8_t b) 
// {   
//     return callback_func(a,b);
// }

// void main() 
// {
//     cal_op(cal_mul,4,10); 
//     cal_op(cal_sum,9,5); 
// }

// 2、回调的实际使用
// 回调可用于多种情况，并广泛用于嵌入式固件开发。
// 它们提供了更大的代码灵活性，并允许我们开发可由最终用户进行微调而无需更改代码的驱动程序。

// 在我们的代码中具有回调功能所需的元素是：

// 将被调用的函数(回调函数)
// 将用于访问回调函数的函数指针
// 将调用回调函数的函数("调用函数")

// 接下来介绍使用回调函数的简单流程。首先声明一个函数指针，用于访问回调函数我们可以简单地将函数指针声明为：

// uint8_t (*p_CallbackFunc)(void);

// 但是对于更清晰的代码，最好定义一个函数指针类型：

// typedef uint8_t (*CallbackFunc_t) (void); 

// **定义回调函数——重要的是要注意回调函数只是一个函数。
// 由于它的使用方式(通过函数指针访问)，我们将其称为回调。**所以这一步只是我们之前声明的指针将指向的函数的定义。

// uint8_t Handler_Event(void) 
// {
// /* code of the function */
// }

// **注册回调函数——这是为函数指针分配地址的操作。
// **在我们的例子中，地址应该是回调函数的地址。可以有一个专门的函数来注册回调函数，如下所示：

// static CallbackFunc_t HandlerCompleted;

// /*用来注册回调函数的功能函数*/
// void CallbackRegister (CallbackFunc_t callback_func) 
// {
//      HandlerCompleted = callback_func;
// }

// /* 注册Handler_Event作为回调*/
// CallbackRegister(Handler_Event);

// 3、代码应用案例
// 3.1、事件回调
// 在这个例子中，我们展示了如何使用回调来处理事件。
// 下面的示例代码是基于较低级别物理通信接口(例如 UART、SPI、I2C 等)构建的数据通信协议栈。
// 通信协议栈实现了两种不同类型的帧——标准通信帧和增强型通信帧。

// 有两种不同的函数用于处理接收到的字节事件。
// 在初始化函数中，函数指针被分配了应该使用的函数的地址用于处理事件，这是注册回调函数的操作。

// /*指向回调函数的函数指针*/
// uint8_t ( *Receive_Byte) ( void );

// /*
//  * 简化的初始化函数
//  * 这里函数指针被分配了一个函数的地址(注册回调函数)
//  */
// void Comm_Init( uint8_t op_mode) {
//         switch ( op_mode ) {
//         case STD_FRAME:           
//             Receive_Byte     = StdRxFSM;
//             break;
//         case ENHANCED_FRAME:  
//             Receive_Byte     = EnhancedRxFSM;
//             break;
//         default:
//             Receive_Byte     = EnhancedRxFSM;
//         }
// }

// /* 这些是在通信栈中实现的函数(回调)
// * 它们不会在任何地方直接调用，而是使用函数指针来访问它们 */
// uint8_t  StdRxFSM(void) 
// {
//     //在这里完成处理工作
// }
// uint8_t  EnhancedRxFSM(void) 
// {
//     //在这里完成处理工作
// }
// 当从物理通信接口(例如 UART)接收到新字节(事件)时，用户应用程序代码会调用我们示例中的回调函数。

// extern uint8_t (*Receive_Byte)( void );
// void receive_new_byte() 
// {
//    Receive_Byte(); 
// }

// 3.2、寄存器中的多个回调
// 这个例子展示了我们如何创建一个寄存器来存储回调函数，它是使用数据类型元素的数组实现的，数据类型是具有成员和成员的结构。
// **用于为寄存器中的每个回调函数分配一个标识(唯一编号)。函数指针被分配与唯一关联的回调函数的地址。**
// 以下实现的是添加和删除回调的功能：

// #define FUNC_REGISTER_SIZE 255  // 回调函数注册池的最大容量（最多存储255个回调函数）
// #define FUNC_ID_MAX 127         // 函数ID的最大值（有效ID范围：1~127）

// //函数指针类型
// 定义回调函数的统一接口：接受两个参数（数据指针p_data和长度len），返回uint8_t（通常表示执行状态）
// typedef  uint8_t (*callback_func) ( uint8_t * p_data, uint16_t len );

// typedef struct {
//     uint8_t           function_id;    // 函数ID（唯一标识一个回调函数）
//     callback_func p_callback_func;    // 指向回调函数的指针
// } function_register_t;

// //一组函数处理程序，每个处理程序都有一个id
// 静态数组：存储所有注册的“ID-函数”映射，容量为FUNC_REGISTER_SIZE（255）
// static修饰：仅在当前文件可见，避免外部修改
// static function_register_t func_register[FUNC_REGISTER_SIZE];

// //注册函数回调
// uint8_t RegisterCallback (uint8_t function_id, callback_func p_callback_func ) {
//     uint8_t    status; // 操作状态（成功/失败）
//     int i;

//     第一步：检查function_id是否有效（有效范围：1~FUNC_ID_MAX）
//     if ((0 < function_id) && (function_id <= FUNC_ID_MAX)) 
//     {
//         //向寄存器添加函数
//         //情况1：p_callback_func不为NULL → 注册/更新回调函数
//         if ( p_callback_func != NULL ) { 
//             //遍历注册池，寻找空位（未注册函数）或相同函数的位置
//             for (i = 0; i < FUNC_REGISTER_SIZE; i++ ) {
//                 //找到空位（p_callback_func为NULL）或已存在该函数 → 覆盖/更新
//                 if (( func_register[i].p_callback_func == NULL ) ||
//                     ( func_register[i].p_callback_func == p_callback_func )) {
//                     func_register[i].function_id = function_id;  // 绑定ID
//                     func_register[i].p_callback_func = p_callback_func;  // 绑定函数
//                     break;   // 找到位置后退出循环
//                 }
//             }

//             // 判断是否成功注册（i未超出数组范围 → 找到位置）
//             if (i != FUNC_REGISTER_SIZE) {
//                 status = SUCESSFULL;  // 假设SUCESSFULL是表示成功的宏
//             } else {
//                 status = FAILURE;  // 注册池已满，无法注册
//             }
//        }

//         //情况2：p_callback_func为NULL → 删除该ID对应的回调函数
//         else { 
//             // 遍历注册池，寻找function_id对应的条目
//             for ( i = 0; i < FUNC_REGISTER_SIZE; i++ ) {
//                 if ( func_register[i].function_id == function_id ) {
//                     func_register[i].function_id = 0;    // 清空ID
//                     func_register[i].p_callback_func = NULL; // 清空函数指针
//                     break;   // 找到后退出循环
//                 }
//             }
//             status = SUCESSFULL; // 无论是否找到，都返回成功（未找到视为已删除）
//         }
//     }

//     //第二步：function_id无效 → 返回失败
//     else {
//         status = FAILURE; /* Invalid argument */
//     }
//     return status;
// }

// 在下面的代码中，我们可以看到一个函数示例，该函数可用于根据函数 id 调用回调。

// //具有特定函数代码的回调函数如何被调用的示例
// uint8_t execute_callback(uint8_t FuncCode, uint8_t * p_data_buf, uint16_t len) 
// {  
//     uint8_t status;
//     status = FAILURE;
//     for( i = 0; i < FUNC_REGISTER_SIZE; i++ ){
//         /* No more callbacks registered, exit. */
//         if( func_register[i].function_id == 0 ){
//             break;
//         }
//         else if( func_register[i].function_id == FuncCode) {
//             status = func_register[i].p_callback_func( p_data_buf, len );
//             break;
//         }
//      }
//      return status;
// }

// 4、结论
// 我们可以编写不使用回调的程序，但是通过将它们添加到我们的工具库中，它们可以使我们的代码更高效且更易于维护。
// 明智地使用它们很重要，否则过度使用回调(函数指针)会使代码难以进行排查和调试。
// ==另一件需要考虑的事情是使用函数指针可能会阻止编译器执行的一些优化(例如函数内联)。==

// 回调函数法 VS 常规法

/** *函数：dlist_print_int，打印输出链表 *参数：dlist:双链表 *返回：void **/
// static void dlist_print_int(DListNode *dlist)
// {
//     DListNode* temp = dlist;
//     while (temp)
//     {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     printf("\n\n");
// }

// 这是我们这个专用的双链表中打印链表数据函数，我们存储的是整数，所以用%d打印。
// 那么，如果我们面向的是通用的双链表呢？

// 我们无法预知其中的数据，可能是整数，也可能是字符串，或者是其它的数据。
// 那么怎么办呢？这里有几种方法：

// 方法一：实现多个函数，需要用到哪个就调哪个

/* 打印整数 */
// static void dlist_print_int(DListNode *dlist)
// {
//     DListNode* temp = dlist;
//     while (temp)
//     {
//         printf("%d ",temp->data);
//         temp = temp->next;
//     }
//     printf("\n\n");
// }

/* 打印字符串 */
// static void dlist_print_string(DListNode *dlist)
// {
//     DListNode* temp = dlist;
//     while (temp)
//     {
//         printf("%s ",temp->data);
//         temp = temp->next;
//     }
//     printf("\n\n");
// }

// 比如存放的是整数，可以调用dlist_print_int函数来打印；
// 存放的是字符串，可以调用dlist_print_string函数来打印。
// 这种方法很简单，但有个缺点：每个函数都很相似，会有大量重复的代码。

// 方法二：传入一个附加的参数来选择打印的方式

// #define PRINT_INT 1 /* 打印选择：整数打印方式  */
// #define PRINT_STR 2 /* 打印选择：字符串打印方式 */
// static void dlist_print(DListNode *dlist, int print_choice)
// {
//     DListNode* temp = dlist;
//     while (temp)
//     {
//         /* 打印整数 */
//         if (PRINT_INT == print_choice)
//         {
//             printf("%d ",temp->data);
//         }
//         /* 打印字符串 */
//         else if (PRINT_STR == print_choice)
//         {
//             printf("%s ",temp->data);
//         }
//         else{}
//         temp = temp->next;
//     }
//     printf("\n\n");
// }

// 这种方法使用一个参数来选择打印的方式。避免了方法一中产生大量重复的代码的问题。
// 但是我们每当要增加新类型时，都得修改这个dlist_print函数，对于一个通用的双链表来说，这样的修改是不够好的。
// 这里dlist_print函数也是通用双链表的一部分，我们应该尽量少去修改它。

// 方法三：回调函数法

/* 数据打印函数指针 */
// typedef void (*DListDataPrintFunc)(void *data);

// /* 通用的打印函数（房子的地基，不轻易改变） */
// static void dlist_print(DListNode *dlist, DListDataPrintFunc print)
// {
//     DListNode* temp = dlist;
//     while (temp)
//     {
//         print(temp->data);
//         temp = temp->next;
//     }
//     printf("\n\n");
// }

/* 这是一个回调函数：打印整数（调用者提供，调用者根据实际需要提供这样一个打印函数） */
// static void dlist_print_int(void* data)
// {
//     printf("%d ",(int)data);
// }

// /* 主函数 */
// int main(void)
// {
//     printf("创建一个双链表:");
//     DListNode *dlist = dlist_create();
//     dlist_print(dlist, dlist_print_int);  /* 注册/使用回调函数 */
//     return 0;
// }

// 首先，我们需要实现一个通用的打印函数dlist_print，把函数指针变量作为其中一个参数传入。
// 其次，我们调用者得根据实际情况实现一个用于打印的回调函数，这里我们实现的的回调函数是dlist_print_int。
// 最后，在用到打印的地方调用dlist_print函数即可。
// 用回调函数法是不是很巧妙？
// 此处，我们用到了typedef来“封装”一个打印链表数据的函数指针类型

// typedef  旧名字  新名字;

// 遇到给函数指针类型、数组类型等定义别名的时候要特别区分。如：

// typedef char ARRAY20[20];
// ARRAY20 a1,a2; /* 等价于char a1[20],a2[20]; */