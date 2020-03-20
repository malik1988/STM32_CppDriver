# STM32_CppDriver
Cpp Driver for STM32, build with STM32CubeIDE


## UART
### 定长接收
#### 1. 原理
开启DMA（普通模式），设定固定长度产生一次接收完成中断。在中断中设置标志位，接收程序只要检测标志位是否有效即可知道有没有接收到一次数据。

#### 2. 适合场景
- 发送后立马接收，应答模式。
- 接收数据长度固定。
- 接收数据格式一致。
- 通讯协议允许接收丢弃。

#### 3. 存在问题
- 没有对所有接收数据进行缓存，存在接收错位（接收到的固定长度数据内容实际上包含两个帧的一部分内容，没法合成一个完整的数据帧）。
- 会有数据丢弃的情况，也因此只适合应答模式。（应答解析失败，发送方可以重新发起）。

#### 4. 优势
- 简单
- 高效
- 应答模式下，只要接收超时时间设置合理，出现接收错位的概率很低。

### 变长接收
#### 1. 原理
开启DMA（循环模式），切设定DMA接收的长度为一个字节，每读取到一个字节进入一次中断，在中断中拼接出一个完整的数据帧。

#### 2. 适合场景
- 接收方一直接收，无法控制接收时序。
- 接收数据长度不固定。
- 接收数据格式固定，例如：帧头+数据（1-N）+校验（帧尾）。
- 通讯协议不允许接收丢弃（启动或者停止时可能存在丢弃一帧）。

#### 3. 存在问题
- 每个字节都需要中断处理，效率较低。
- 接收处理时间必须小于下个数据到来时间，否则会出现数据覆盖。

#### 4. 优势
- 严格的数据协议判定