using Microsoft.EntityFrameworkCore;

public class BloggingContext : DbContext
{
    public DbSet<Blog> Blogs { get; set; }

    private readonly string connectionString =
        "server=localhost;port=3306;database=efcore_mysql_test;user=root;password=Linxing77;";

    protected override void OnConfiguring(DbContextOptionsBuilder options)
    {
        options.UseMySql(
            connectionString,
            ServerVersion.AutoDetect(connectionString)
        );
    }
}

public class Blog
{
    public int BlogId { get; set; }

    public string? Url { get; set; }
}