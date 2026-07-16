<h1 align="center">E02 - Aplicaciones Prácticas de las Colas</h1>

> [!TLDR]
> Las colas modelan cualquier sistema de atención por orden de llegada: **spoolers de impresión**, **scheduling de CPU**, **buffers de red**, **sistemas de mensajería** y **simulaciones de filas de espera**.

## Enunciado

¿Indique al menos un uso de las colas en una aplicación?

## Respuesta

Las colas se utilizan extensamente en la informática para gestionar recursos compartidos de manera ordenada y sincronizar la transferencia asíncrona de datos.

1. **Sistemas de Impresión (Spooler de Impresión):** Cuando múltiples usuarios envían documentos a una impresora compartida, los trabajos se almacenan en una cola de impresión. La impresora atiende los trabajos secuencialmente en estricto orden de llegada (FIFO).

2. **Planificación de Procesos en Sistemas Operativos (CPU Scheduling):** Los sistemas operativos utilizan colas de procesos listos (`Ready Queue`) para decidir qué hilo de ejecución o proceso recibirá tiempo de procesador. Los procesos listos se encolan y el planificador los despacha según políticas FIFO u otras variantes prioritarias.

3. **Búferes de Transmisión de Red e I/O:** En las transmisiones de sockets TCP o lectura de archivos por bloques, los paquetes de datos que llegan de la red se encolan temporalmente en un búfer de memoria mientras el programa principal los consume. Esto previene la pérdida de datos cuando la velocidad de recepción es mayor que la velocidad de procesamiento.

4. **Sistemas de Mensajería y Eventos (Message Brokers):** Plataformas como RabbitMQ, Apache Kafka o los sistemas de colas de correo electrónico encolan peticiones o notificaciones para procesarlas asíncronamente en servidores dedicados.

5. **Simulaciones de Filas de Espera:** Modelado matemático de atención al cliente (bancos, supermercados, call centers) para analizar tiempos de espera y optimizar recursos.
