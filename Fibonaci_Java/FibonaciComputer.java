import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;
import java.math.RoundingMode;
import java.util.ArrayList;
import java.util.List;

public class FibonaciComputer implements Runnable{


   private List<BigInteger> fibonaciNumbers;
   private Integer nr_threads;
   private Integer upperLimit;
   private Integer lowerLimit;

    public FibonaciComputer(List<BigInteger> fibonaciNumbers, Integer nr_threads, Integer upperLimit, Integer lowerLimit) {
        this.fibonaciNumbers = fibonaciNumbers;
        this.nr_threads = nr_threads;
        this.upperLimit = upperLimit;
        this.lowerLimit = lowerLimit;
    }

    public void setFibonaciNumbers(List<BigInteger> fibonaciNumbers) {
        this.fibonaciNumbers = fibonaciNumbers;
    }

    public void setNr_threads(Integer nr_threads) {
        this.nr_threads = nr_threads;
    }

    public void setUpperLimit(Integer upperLimit) {
        this.upperLimit = upperLimit;
    }

    public void setLowerLimit(Integer lowerLimit) {
        this.lowerLimit = lowerLimit;
    }

    public List<BigInteger> getFibonaciNumbers() {
        return fibonaciNumbers;
    }

    public Integer getNr_threads() {
        return nr_threads;
    }

    public Integer getUpperLimit() {
        return upperLimit;
    }

    public Integer getLowerLimit() {
        return lowerLimit;
    }

    @Override
    public void run() {
        BigDecimal s5= BigDecimal.valueOf(5.0);

        s5=s5.sqrt(new MathContext((int)(0.2*upperLimit)));
        BigDecimal phi= BigDecimal.valueOf(1.0);

        phi=phi.add(s5,new MathContext((int)(0.2*upperLimit)));
        phi=phi.setScale((int)(0.2*upperLimit),RoundingMode.FLOOR);
        phi=phi.divide(BigDecimal.valueOf(2.0),new MathContext((int)(0.2*upperLimit)));


        for(int k=lowerLimit;k<=upperLimit;k+=nr_threads)
        {
            BigDecimal temp=phi;
            temp=temp.setScale((int)(0.2*upperLimit),RoundingMode.FLOOR);

            temp=temp.pow(k,new MathContext((int)(0.2*upperLimit)));
            temp=temp.divide(s5,new MathContext((int)(0.2*upperLimit)));
            temp=temp.add(BigDecimal.valueOf(0.5));
            temp=temp.round(new MathContext((int)(0.2*upperLimit)));
            BigInteger result=temp.toBigInteger();
            fibonaciNumbers.set(k,result);
        }

    }
}
