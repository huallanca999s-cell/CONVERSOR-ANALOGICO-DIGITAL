# Sistema de Conversión Analógica-Digital (ADC) y Digital-Analógica (DAC) con Arduino

## Descripción del Proyecto 
Este proyecto abarca el diseño, simulación e implementación de un sistema mixto de conversión de señales utilizando la plataforma **Arduino**. Su importancia radica en la integración completa del ciclo de procesamiento de señales: se captura y digitaliza una variable analógica a través del **ADC interno del microcontrolador**, para luego ejecutar el proceso inverso de reconstrucción analógica utilizando un **DAC0808** de 8 bits. La etapa de salida se complementa con un amplificador operacional **LM741** en configuración de convertidor corriente a voltaje ($I/V$), logrando una solución integral para el control y adquisición de datos en tiempo real.

---

## Arquitectura y Componentes del Sistema

### 1. Etapa de Digitalización (ADC)
* **Microcontrolador:** Arduino (Atmega328P).
* **Resolución ADC:** 10 bits ($2^{10} = 1024$ niveles de cuantificación).
* **Rango Dinámico:** $0\text{V} - 5\text{V}$ (Voltaje de referencia $V_{REF} = 5\text{V}$).
* **Procesamiento:** Captura de señales analógicas y generación de un bus de datos digital para la etapa de reconstrucción.

### 2. Etapa de Reconstrucción (DAC)
* **CI DAC:** DAC0808 (Conversor Multiplying D/A de 8 bits).
* **Resolución DAC:** 8 bits ($256$ niveles discretos de salida).
* **Modo de Salida:** Corriente proporcional de salida ($I_{OUT}$).

### 3. Acondicionamiento de Salida ($I$ a $V$)
* **Amplificador Operacional:** LM741.
* **Configuración:** Transimpedancia / Convertidor Corriente a Voltaje ($I/V$).
* **Diseño:** Basado en las especificaciones del *datasheet* del DAC0808 para convertir la salida de corriente $I_{OUT}$ en un rango de voltaje estable y escalado ($0\text{V} - 5\text{V}$ o según $V_{REF}$).

---

## Diagrama Esquematico
La siguiente imagen presenta el esquema general del proyecto. El sistema utiliza un sensor LM35 junto con la plataforma Arduino para realizar la conversión analógica a digital (ADC) de la temperatura. Los 8 bits resultantes de la conversión se despliegan mediante un arreglo de LEDs y se ingresan al DAC0808 para reconvertir la señal a un formato analógico, permitiendo así la regulación y encendido automático de un ventilador.

  <img src="DIAGRAMA%20ESQUEMATICO/ESQUEMATICO PROTEUS.jpg" alt="Esquema del Circuito" width="800">
</p>

## Estructura del Repositorio
```text

├── CODIGO/                       # Código fuente de Arduino (.ino)
├── DIAGRAMA ESQUEMATICO/         # Archivos de simulación y esquemáticos
├── DOCUMENTACION/                # Paper en formato IEEE y presentación PPT
└── README.md                     # Documentación principal
```
---
**Autor:** Erick Isaias Huallanca Perez  
**Contacto:** [LinkedIn](https://www.linkedin.com/in/erick-isaias-huallanca-perez-925b7632b) | [huallanca999s@gmail.com](mailto:huallanca999s@gmail.com)
